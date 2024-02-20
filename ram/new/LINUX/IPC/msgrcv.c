#include"header.h"
struct msgbuf
{
	long mtype;
	char data[200];
};
int main(int argc,int *argv[])
{
	if(argc!=2)
	{
		printf("Usage.../rcv msgtype\n");
		return;
	}
	struct  msgbuf v;
	//v.mtype=atoi(argv[1]);
	//strcpy(v.data,argv[2]);
	int id;
	id=msgget(1,IPC_CREAT|0660);
	if(id<0)
	{
		perror("msgget");
		return;
	}
	msgrcv(id,&v,sizeof(v.data),atoi(argv[1]),0);
	perror("msgrcv");
	printf("data:%s\n",v.data);
}
