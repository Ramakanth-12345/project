	
obj-m += mychar.o
 
all:
	 make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	 $(CC) mytest.c -o mytest
clean:
	 make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	 rm mytest
