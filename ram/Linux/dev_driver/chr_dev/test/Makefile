obj-m += test.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	$(CC) test_app.c -o test_app

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm test_app
