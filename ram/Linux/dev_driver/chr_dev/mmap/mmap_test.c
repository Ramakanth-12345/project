#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>

int main()
{
	int fd;
	char *data;

	printf("Starting of the program\n");
	fd=("/dev/mem",O_RDWR);
	if(fd<0)
		printf("device is not opened\n");
	data=mmap(NULL,0x100,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
	printf("%p\n",data);
	printf("%c\n",data[0]);
	printf("%c\n",data[1]);
	
	data=munmap(NULL,0x100);

	close(fd);
}

