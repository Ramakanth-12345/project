#include"header.h"
void isr(int n)
{
	printf("in isr..\n");
	//sleep(5);
	printf("out isr..\n");
}
main()
{
	if(fork()==0)
	{
	printf("in child..%d\n",getpid());
	while(1);
	}
	else
	{
		struct sigaction v;
		v.sa_handler=isr;
		v.sa_flags=SA_NOCLDSTOP|SA_NOCLDWAIT;
		sigemptyset(&v.sa_mask);
		sigaction(17,&v,0);
		while(1);
	}
}

