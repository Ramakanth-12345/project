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
	printf("inode number=%d\nsize of file=%d\nnumber of blocks=%d\npermission=%o\n",v.st_ino,v.st_size,v.st_blocks,v.st_mode);
}
