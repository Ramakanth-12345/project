#include"header.h"

#define DEVICE "/dev/MY_DEV"

int8_t write_buf[1024],read_buf[1024];

int main()
{
	int fd,ch;
//	int8_t write_buf[1024],read_buf[1024];
	printf("Welcome to the demo of character device driver\n");

	fd=open("/proc/chr_proc",O_RDWR);
	if(fd<0)
	{
		printf("file %s either does not exist or has been locked by another process\n",DEVICE);
		return 0;
	}
	while(1)
	{
		printf("please enter your options\n");
	   	printf("			1.Write		\n");
		printf("			2.Read		\n");
		printf("			3.Exit		\n");
		scanf("%d",&ch);
		printf("your option is %d\n",ch);
		switch(ch)
		{
			case 1:
				printf("enter the data\n");
				scanf("%[^\t\n]s",write_buf);
				write(fd,write_buf,strlen(write_buf)+1);
				break;
			case 2:
				printf("Data Reading is..\n");
				read(fd,read_buf,1024);
				printf("Data=%s\n",read_buf);
				break;
			case 3:
				close(fd);
				exit(1);
				break;
			default:
				printf("Enter correct option \n");
				break;
		}
	}
	close(fd);
}
