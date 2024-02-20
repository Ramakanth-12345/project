#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
main()
{
	int a[3];
	if((a[0]=fork())==0)
	{
		int d;
		srand(getpid());
		d=rand()%10+1;
		printf("In C1...%d %d..\n",d,getpid());
		sleep(d);
		printf("out c1...\n");
		exit(1);
	}
	else
	{
		if((a[1]=fork())==0)
        	{
                int d;
               		 srand(getpid());
                	d=rand()%10+1;
                	printf("In C2...%d %d..\n",d,getpid());
               		sleep(d);
                	printf("out c2...\n");
                	exit(2);
        	}
		else
		{
			if((a[2]=fork())==0)
       		 	{
                	int d;
               		srand(getpid());
                	d=rand()%10+1;
               		printf("In C3...%d %d..\n",d,getpid());
              		sleep(d);
               		printf("out c3...\n");
                	exit(3);
       			 }
			else
			{
				int r,s;
				printf("In parent..%d\n",getpid());
				while((r=wait(&s))!=-1)
				{
					s=s<<8;
					printf("***c%d***%d**\n",s,a[s-1]);
				}
				printf("Out Parent..\n");
			}

		}

	}
}
