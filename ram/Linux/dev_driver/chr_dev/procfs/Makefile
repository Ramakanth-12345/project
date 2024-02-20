
obj-m += procfs.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	#$(CC) ioctl_device.c -o ioctl
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	#rm ioctl
