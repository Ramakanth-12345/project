#include"header.h"
int main(int argc,int *argv[])
{
	int id,ret;
	if(argc!=3)
	{
		printf("Usage:./set semnum semval\n");
		return;			
	}
	id=semget(4,5,IPC_CREAT|0660);
	perror("semget");
	printf("semphore id=%d\n",id);
	ret=semctl(id,atoi(argv[1]),SETVAL,atoi(argv[2]));
	perror("semctl");
	printf("ret=%d\n",ret);
}
