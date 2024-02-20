#include"header.h"
int main()
{
	int fd1,fd2;
	char a[20];
	mkfifo("f1",0666);
	mkfifo("f2",0666);
	fd1=open("f1",O_RDWR);
	perror("open_1");
	fd2=open("f2",O_RDWR);
	perror("open_2");
	if(fork()==0)
	{
		while(1)
		{
			read(fd1,a,sizeof(a));
			printf("\t%s\n",a);
		}
	}
	else
	{
		while(1)
		{
			scanf("%s",a);
			write(fd2,a,strlen(a)+1);
		}
	}

}
