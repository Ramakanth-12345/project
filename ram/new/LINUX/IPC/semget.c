#include"header.h"
int main(int argc,int *argv[])
{
	int id,ret;
	if(argc!=2)
	{
		printf("Usage:./get semnum\n");
		return;			
	}
	id=semget(4,5,IPC_CREAT|0660);
	perror("semget");
	printf("semphore id=%d\n",id);
	ret=semctl(id,atoi(argv[1]),GETVAL);
	perror("semctl");
	printf("semval ret=%d\n",ret);
}
