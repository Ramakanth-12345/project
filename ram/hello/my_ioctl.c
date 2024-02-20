#include"header.h"

#define WR_DATA _IOW('a','a',int32_t*)
#define RD_DATA _IOR('a','b',int32_t*)

int main()
{
	int fd;
	int32_t val,num;
	printf("\n IOCTL based character device driver operation from user\n");
	fd=open("/dev/my_device",O_RDWR);
	if(fd<0)
	{
		printf("cannot open the file\n");
		return 0;
	}
	printf("ENter the data to send\n");
	scanf("%d",&num);

	printf("Writing val to the driver\n");
	ioctl(fd,WR_DATA,(int32_t*)&num);

	printf("Reading from the driver\n");
	ioctl(fd,RD_DATA,(int32_t*)&val);

	printf("closing the driver\n");
	close(fd);
}


