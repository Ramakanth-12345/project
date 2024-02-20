#include"header.h"
int chldpid;
void isr(int n)
{
	printf("IN ISR..%d\n",n);
	if(n==SIGCHLD)
	{
		printf("child complete\n");
	}
	else if (n==SIGALRM)
	{
		if(kill(chldpid,0)!=-1)
		{
			printf("child terminatred\n");
			signal(SIGCHLD,SIG_DFL);
			kill(chldpid,9);
		}
	}
}
main()
{
	if((chldpid=fork())==0)
	{
		int d;
		srand(getpid());
		d=rand()%10+1;
		printf("In child..%d\n",d);
		sleep(d);
		printf("out child..\n");
	}
	else
	{
		struct sigaction v;
		v.sa_handler= isr;
		sigemptyset(&v.sa_mask);
		v.sa_flags=SA_NOCLDSTOP|SA_NOCLDWAIT;
		sigaction(SIGCHLD,&v,0);
		v.sa_flags=0;
		sigaction(SIGALRM,&v,0);
		alarm(5);
		printf("hello\n");
		sleep(5);

	}
}
