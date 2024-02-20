#include"header.h"
void isr(int n)
{
	printf("in isr\n");
	sleep(10);
	printf("out isr\n");
}
main()
{
/*	if(fork()==0)
	{
		printf("in child..\n");
		sleep(10);
		printf("out child\n");
	}*/
//	else
//	{
		signal(SIGINT,isr);
		signal(SIGQUIT,isr);
		while(1);
//	}
}
