#include"headers.h"
int main(int argc,char **argv)
{
	int fd;
	char ch;
	if(argc<2){printf("error\n");return 0;}
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		exit(0);
	}

	while(read(fd,&ch,1)==1)
	{
		printf("%c",ch);
	}
	close(fd);

}
