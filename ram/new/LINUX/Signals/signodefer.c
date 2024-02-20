#include"header.h"
void isr(int n)
{
	printf("In Isr..\n");
	sleep(5);
	printf("Out Isr..\n");
}
main()
{
	struct  sigaction v;
	v.sa_handler=isr;
	sigemptyset(&v.sa_mask);
	v.sa_flags-SA_NODEFER;
	sigaction(SIGINT,&v,0);
	while(1);
}
