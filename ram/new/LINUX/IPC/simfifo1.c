#include"header.h"
int main()
{
	int fd;
	char a[15],ch;
	mkfifo("fifofile",0666);
	perror("mkfifo");
	fd=open("fifofile",O_WRONLY);
	perror("open");
	do
	{
		printf("process 1\n");
		printf("enter data\n");
		scanf("%s",a);
		write(fd,a,strlen(a)+1);
		perror("write");
	}while(1);


}
