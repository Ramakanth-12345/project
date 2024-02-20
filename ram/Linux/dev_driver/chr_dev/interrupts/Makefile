#obj-m += interrupt.o
#obj-m += queue_dynamic.o
obj-m += own_workqueue.o

KDIR := /lib/modules/$(shell uname -r)/build

PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules

install:
	$(MAKE) -C $(KDIR) M=$(shell pwd) module_install

clean:
	$(MAKE) -C $(KDIR) M=$(shell pwd) clean

