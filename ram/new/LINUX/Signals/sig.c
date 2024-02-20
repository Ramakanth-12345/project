#include<stdio.h>
#include<stdlib.h>
main()
{
	int s,r,ret;
	printf("In parent...%d\n",getpid());
	if((r=fork())==0)
	{
		printf("In child..%d\n",getpid());
		sleep(40);
		exit(0);
	}
	else
	{
		while(1)
		{
			ret=waitpid(r,&s,WNOHANG|WUNTRACED|WCONTINUED);
			if(ret==-1)
				break;
			if(ret==0)
				continue;
			if(WIFEXITED(s))
				printf("Normal Termination..with exit status %d\n",WIFEXITED(s));
			else if(WIFSIGNALED(s))
				printf("Signal Termination....by signal %d\n",WTERMSIG(s));
			else if(WIFSTOPPED(s))
				printf("Stopped..by signail %d\n",WSTOPSIG(s));
			else if(WIFCONTINUED(s))
				printf("Stopped Process continued with signal 18\n");
			sleep(5);
		}
		printf("Out Parent\n");
	}

}
