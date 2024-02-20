#include"header.h"
void my_isr(int n)
{
	printf("In ISR...%d\n",n);
	signal(3,SIG_DFL);
}
main()
{
	signal(SIGQUIT,my_isr);
	printf("%d\n",getpid());
	printf("hi\n");
	while(1);
	//printf("hi..\n");
}

