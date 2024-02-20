#include"header.h"
void isr(int n)
{
	printf("in isr..\n");
	sleep(10);
	printf("out isr..\n");
}
main()
{
	struct sigaction v;
	v.sa_handler=isr;
	sigemptyset(&v.sa_mask);
	v.sa_flags=0;
	sigaction(SIGINT,&v,0);
	while(1);
}
