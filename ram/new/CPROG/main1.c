/*
 * Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries
 *
 * File:            main.c
 * Project:         sdadc-example-project
 * Date:            Nov 22, 2018
 * Compiler:        arm-gcc v6.3.1
 * 
 * Simple "GCC Executable" Code Example Project using the Sigma-Delta ADC.
 *
 * Continuous manual triggering/conversion on light sensor signal connected to AIN1+ and AIN1-
 * 
 * Hardware Configuration: SAM C21 Xplained PRO (ATSAMC21J18A) with IO1 Xplained Extension Header
 *
 */

 
#include "sam.h"

#define LED_INT PORT_PA15
#define SW0		PORT_PA28
#define SW0_PIN	(PIN_PA28 & 0x1F)
#define LED_EXT PORT_PB12
#define NEGDRV	PORT_PB13

#define SDADCIN1P PORT_PB09
#define SDADCIN1P_PIN  (PIN_PB09 & 0x1F)
#define SDADCIN1N PORT_PB08
#define SDADCIN1N_PIN  (PIN_PB08 & 0x1F)

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7
#define GPIO_PIN_FUNCTION_I 8

#define OSR64		0
#define OSR128		1
#define OSR256		2
#define OSR512		3
#define OSR1024		4


void ClkInit(void)
{
	MCLK->APBCMASK.reg = MCLK_APBCMASK_SDADC;					// Turn On SDADC APB Clock
	GCLK->GENCTRL[1].bit.SRC = GCLK_GENCTRL_SRC_OSC48M_Val;		// Set GCLK1 to use OSC48M (divided by 12...  4 MHz)
	while(GCLK->SYNCBUSY.bit.GENCTRL1);							//   (wait for sync)
	GCLK->GENCTRL[1].bit.DIV = 4;								// Divide by 4 - 1 MHz 
	while(GCLK->SYNCBUSY.bit.GENCTRL1);							//   (wait for sync)
	GCLK->GENCTRL[1].bit.GENEN = 1;								// Enable GCLK1
	while(GCLK->SYNCBUSY.bit.GENCTRL1);							//   (wait for sync)
	GCLK->GENCTRL[1].bit.OE = 1;								// Enable Output Pin
	while(GCLK->SYNCBUSY.bit.GENCTRL1);							//   (wait for sync)
	GCLK->PCHCTRL[35].reg = GCLK_PCHCTRL_CHEN | GCLK_PCHCTRL_GEN_GCLK1;	  // Enable GCLK1 to drive the SDADC
}

void IOInit(void)
{
	PORT->Group[0].DIRSET.reg = LED_INT;				// Enable output pin to drive LED0
	
	PORT->Group[0].DIRCLR.reg = SW0;					// Enable input pin for SW0
	PORT->Group[0].OUTSET.reg = SW0;					// Enable pull up on SW0 pin
	PORT->Group[0].PINCFG[SW0_PIN].reg = PORT_PINCFG_INEN | PORT_PINCFG_PULLEN;
	PORT->Group[0].CTRL.reg = SW0;						// Enable Sampling for SW0 pin
	
	PORT->Group[1].DIRSET.reg = LED_EXT;				// Enable output pin to drive LED on ATIO1-XPRO
	
	PORT->Group[1].DIRSET.reg = NEGDRV;					// Drive negative side of SDADC input
	PORT->Group[1].OUTCLR.reg = NEGDRV;					// Negative side is driven low, because to provide GND reference to light sensor
	
	PORT->Group[1].DIRCLR.reg = SDADCIN1P;							// Disable Output Driver on the ADC+ pin
	PORT->Group[1].PINCFG[SDADCIN1P_PIN].reg = PORT_PINCFG_PMUXEN;	// Use the PMUX to select the function for the ADC+ pin
	
	PORT->Group[1].DIRCLR.reg = SDADCIN1N;							// Disable Output Driver on the ADC- pin
	PORT->Group[1].PINCFG[SDADCIN1N_PIN].reg = PORT_PINCFG_PMUXEN;	// Use the PMUX to select the function for the ADC- pin

																	// Choose SDADC function for the ADC+ and ADC- pins
	PORT->Group[1].PMUX[(SDADCIN1N_PIN>>1)].reg = PORT_PMUX_PMUXO(GPIO_PIN_FUNCTION_B) | PORT_PMUX_PMUXE(GPIO_PIN_FUNCTION_B) ;
	
	// Route GCLK1 Output to pin to measure frequency - for debug purposes
	//PORT->Group[0].DIRSET.reg = PORT_PA15;
	//PORT->Group[0].PINCFG[15].reg = PORT_PINCFG_PMUXEN;
	//PORT->Group[0].PMUX[7].reg = PORT_PMUX_PMUXO(GPIO_PIN_FUNCTION_H);
}

void SDADCInit(void)
{
	SDADC->CTRLA.bit.ENABLE = 0;						// Turn off module to allow configuration
	while(SDADC->SYNCBUSY.bit.ENABLE);					//   (wait for sync)
	SDADC->CTRLB.bit.SKPCNT = 4;						// Number of samples to skip when module is started
	SDADC->CTRLB.bit.OSR = OSR1024;						// Oversampling Ratio - 1024
	SDADC->CTRLB.bit.PRESCALER = 0;						// Set CLK_SDADC to GCLK/2 (1MHz/2...  FS=CLK_SDADC/4 = 125 KHz)
	SDADC->REFCTRL.bit.REFRANGE = 2;					// 2.4v < Vref < 3.6v
	SDADC->REFCTRL.bit.REFSEL = SDADC_REFCTRL_REFSEL_INTVCC_Val;  // Vref = VCC
	SDADC->GAINCORR.reg = 1;							// Set Gain Correction to 1
	while(SDADC->SYNCBUSY.bit.GAINCORR);				//   (wait for sync)
	SDADC->OFFSETCORR.reg = 0;							// Set Offset Correction to 0
	while(SDADC->SYNCBUSY.bit.OFFSETCORR);				//   (wait for sync)
	SDADC->SHIFTCORR.reg = 8;							// Set Shift Correction to 8:  24-bit->16-bit
	while(SDADC->SYNCBUSY.bit.SHIFTCORR);				//   (wait for sync)
	SDADC->INPUTCTRL.bit.MUXSEL = 1;					// Set Input Mux to AIN1
	while(SDADC->SYNCBUSY.bit.INPUTCTRL);				//   (wait for sync)
	
	SDADC->CTRLA.bit.ENABLE = 1;						// Turn on module
	while(SDADC->SYNCBUSY.bit.ENABLE);					//   (wait for sync)
}

int main(void)
{
	volatile int32_t result;
	
    /* Initialize the SAM system */
    SystemInit();
	
	ClkInit();		// Initialize Peripheral Clocks
	IOInit();		// Initialize I/O Pins
	SDADCInit();	// Initialize Sigma Delta ADC Module


    /* Replace with your application code */
    while (1) 
    {
		// For Debug Purposes - Read switch and output on LED, so that you can verify program is
		// looping by pressing the button and seeing if it responds.  If not, the code is hung somewhere.
		
		if (PORT->Group[0].IN.reg & SW0)			// Read SW0
		{
			PORT->Group[0].OUTSET.reg = LED_INT;	// If SW0 not pressed, turn off LED
		}
		else
		{
			PORT->Group[0].OUTCLR.reg = LED_INT;	// If SW0 is pressed, turn on LED
		}
		
		
		SDADC->INTFLAG.reg = 0;						// Clear Interrupt Flags
		SDADC->SWTRIG.bit.START = 1;				// Trigger SDADC Conversion
		PORT->Group[1].OUTCLR.reg = LED_EXT;		// Debug - LED on when converting
		while (!SDADC->INTFLAG.bit.RESRDY);			// Wait for Conversion to Complete
		PORT->Group[1].OUTSET.reg = LED_EXT;		// Debug - LED off when conversion is finished
		result = SDADC->RESULT.reg;					// Read result
		__NOP();									// Place Breakpoint Here
		
    }
}
