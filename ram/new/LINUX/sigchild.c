#include"header.h"
void isr(int n)
{
	printf("in isr\n");
	wait(0);
}
main()
{
	if(fork()==0)
	{
		printf("in child..\n");
		sleep(10);
		printf("out child\n");
	}
	else
	{
		signal(SIGCHLD,isr);
		while(1);
	}
}
