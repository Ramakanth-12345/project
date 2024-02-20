#include"header.h"
main(int argc,int *argv[])
{
	int fd,fd1,ret;
	char a[10];
	if(argc!=3)
	{
		printf("Usage../a.out fd fd1\n");
		return;
	}
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("openSRC");
		return;
	}
	fd1=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0660);
	if(fd1<0)
	{
		perror("openDEST");
		return;
	}
	do{
		memset(a,'\0',sizeof(a));
		ret=read(fd,a,4);
		write(fd1,a,ret);
	}
	while(ret);
	close(fd);
	close(fd1);
}

