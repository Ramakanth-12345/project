#obj-m += ex01_simple.o
#obj-m += ex02_simple_init.o
#obj-m += ex02_simple_exit.o

#obj-m := ex0202_simple.o
#ex0202_simple-objs := ex02_simple_init.o ex02_simple_exit.o	

#obj-m := ex01_simple.o

#obj-m += ex03_simple.o

#obj-m := ex04_exporting_symbols.o
#obj-m += ex04_using_symbols.o 

obj-m :=ex05_module_param.o

#obj-m := ex06_simple_chrdev.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
