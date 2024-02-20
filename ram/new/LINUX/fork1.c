/*C program to creat 3 childs using fork() and Sleep for below 10 sec using random fun()*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pid,pid1,pid2,d,r,n;
	//srand(time(0));
	//d=rand()%10+1;
	pid=fork();
	if(pid==0)
	{
		srand(getpid());
	        d=rand()%10+1;
		sleep(d);
		printf("child[1] --> pid = %d and ppid = %d,time=%d\n",getpid(),getppid(),d);
	}
	else
	{
		srand(getpid());
		n=rand()%10+1;
		pid1=fork();
		if(pid1==0)
		{
			sleep(n);
			printf("child[2] --> pid=%d and ppid = %d,time=%d\n",getpid(),getppid(),n);
		}
		else
		{
			//srand(getpid());
			//r=rand()%10+1;
			pid2=fork();
			if(pid2==0)
			{
				printf("child[3] --> pid = %d and ppid = %d,time=%d\n",getpid(),getppid(),r);
				sleep(d);
			}
			else
			{	
				//sleep(r);
				printf("parent --> pid = %d\n",getpid());
			}
		}
	}
	return 0;
}
