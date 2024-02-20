#include<stdio.h>
int main()
{
	int i;
	printf("Hello...\n");
	for(i=0;i<3;i++)
	{
		if(fork()==0)
		{
			printf("PID %d PPID %d\n",getpid(),getppid());
	       break;
			       
		}
		else;
			//break;
	}

}
