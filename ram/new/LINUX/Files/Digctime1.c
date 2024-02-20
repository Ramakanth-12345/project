#include"header.h"
main(int argc,int **argv)
{
	struct stat v;
	if(argc!=2)
	{
		printf("Usage:./a.out filename\n");
		return;
	}
	if(stat(argv[1],&v)<0)
	{
		perror("stat");
		return;
	}
	printf("atime=%s\n",ctime(&v.st_atime));
	printf("mtime=%s\n",ctime(&v.st_mtime));
	printf("ctime=%s\n",ctime(&v.st_ctime));
}
