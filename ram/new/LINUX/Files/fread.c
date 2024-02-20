#include"header.h"
main()
{
	int fd,ret;
	char a[60];
	fd=open("data",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return;
	}
	printf("fd=%d\n",fd);
	ret=read(fd,a,60);
	perror("open");
	printf("ret=%d\n",ret);
	printf("%s",a);
}
