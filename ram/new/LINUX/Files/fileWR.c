#include"header.h"
main()
{
	int fd;
	fd=open("datar",O_WRONLY|O_CREAT|O_TRUNC,0577);
	if(fd>0)
	{
		perror("open");
		return;
	}
	printf("fd=%d\n",fd);
	printf("pid=%d\n",getpid());
	while(1);
}
