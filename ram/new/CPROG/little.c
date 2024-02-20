#include <stdio.h>
#include <inttypes.h>
typedef union
{
    //integer variable
    uint32_t u32RawData;
    //array of character
    uint8_t  au8DataBuff[4];
} RawData;
int main(void)
{
	uint32_t a;
    RawData uCheckEndianess;
    //assign the value
    printf("enter the value\n");
    scanf("%d",&a);
    
    uCheckEndianess.u32RawData =a ;
    
    //check the array first index value
    
    if (uCheckEndianess.au8DataBuff[0] ==a)
    {
        printf("little-endian");
    }//check the array first index value
    
    else if (uCheckEndianess.au8DataBuff[0] == 0)
    {
        printf("big-endian");
    }
    return 0;
}
