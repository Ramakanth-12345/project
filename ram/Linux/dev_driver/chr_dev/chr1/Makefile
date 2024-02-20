obj-m += chr_dev1.o

#all:
	#make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
#clean:
	#make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean



KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules
	#$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules 

install:
	$(MAKE) -C $(KDIR) M=$(shell pwd) module_install
#	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) module_install

clean:
	$(MAKE) -C $(KDIR) M=$(shell pwd) clean
#	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
