#include"header.h"
main()
{
	int fd;
	fd=open("data",O_RDONLY);
	if(fd>0)
	{
		perror("open");
		return;
	}
	printf("fd=%d\n",fd);
	printf("pid=%d\n",getpid());
	while(1);
}
