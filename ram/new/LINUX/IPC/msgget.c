#include"header.h"
main(int argc,int *argv[])
{
	int id;
	if(argc!=2)
	{
		printf("Usage:./a.out keyno\n");
		return;
	}
	id=msgget(atoi(argv[1]),IPC_CREAT|0600);
	if(id<0)
	{
		perror("msgget");
		return;
	}
	printf("id=%d\n",id);
}
