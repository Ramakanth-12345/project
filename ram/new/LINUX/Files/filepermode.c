#include"header.h"
main(int argc,int **argv)
{
	struct stat v;
	int mode;
	if(argc!=2)
	{
		printf("Usage:./a.out filename\n");
		return;
	}
	if(lstat(argv[1],&v)<0)
	{
		perror("stat");
		return;
	}
	printf("mode=%o\n",v.st_mode);
	if(S_ISREG(v.st_mode))
		printf("Regular file\n");
	if(S_ISDIR(v.st_mode))
                printf("Directory file\n");
	if(S_ISBLK(v.st_mode))
                printf("Block file\n");
	if(S_ISLNK(v.st_mode))
                printf("LINK file\n");
	if(S_ISFIFO(v.st_mode))
                printf("pipe file\n");
	if(S_ISCHR(v.st_mode))
                printf("Character file\n");
	if(S_ISSOCK(v.st_mode))
                printf("Socket file\n");
}
