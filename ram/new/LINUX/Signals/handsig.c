#include"header.h"
int c;
void my_isr(int sig)
{
	printf("\nIN isr....%d\n",sig);
	if(sig==2)
	{
		printf("%d:SIGINT signal is delivered\n",sig);
		printf("square of %d is %d\n",c,c*c);
	}
	else if(sig==3)
	{
		printf("%d:SIGQUIT signal is deliverd\n",sig);
		printf("cube of %d is %d\n",c,c*c*c);
	}
}
main()
{
	signal(SIGINT,my_isr);
	signal(SIGQUIT,my_isr);
	printf("PID:%d\n",getpid());
	printf("Enter number\n");
	scanf("%d",&c);
	pause();
	pause();
}

