#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<unistd.h>

#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)

int main()
{
	int fd;
	int32_t value,number;

	printf("...WELCOME TO IOCTL DEVICE\n......");
	printf("...\nopening the driver\n....");

	fd=("/dev/procfs_device",O_RDWR);
	if(fd<0)
	{
		printf("cannot open the device\n");
		return 0;
	}

	printf("Enter the value to send\n");
	scanf("%d",&number);
	printf("Writing the value to the driver\n");
	ioctl(fd,WR_VALUE,(int32_t*)&number);


	printf("Reading the value from the driver\n");
	ioctl(fd,RD_VALUE,(int32_t*)&value);
	printf("Value = %d\n",value);

	printf("closing the Driver\n");
	close(fd);
}
