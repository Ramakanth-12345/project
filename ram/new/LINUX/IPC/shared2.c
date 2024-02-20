#include"header.h"
main(int argc,int *argv[])
{
	int id;
	char *p;
	id=shmget(atoi(argv[1]),atoi(argv[2]),IPC_CREAT|0666);
	perror("shmget");
	p=shmat(id,0,0);
	printf("P=%u\n",p);
	printf("data:%s\n",p);

}

