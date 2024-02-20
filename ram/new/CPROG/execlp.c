#include<stdio.h>
#include<unistd.h>
main()
{
	if(fork()==0)
	{
		printf("**** child1 ls**\n");
		execlp("ls","ls",NULL);
	}
	else
	{
		wait(0);
		if(fork()==0)
		{
			printf("**** child2 ls**\n");
               		execlp("pwd","pwd",NULL);

		}
		else
		{
			wait(0);
			if(fork()==0)
			{
				printf("**** child3 ls**\n");
                		execlp("cal","cal",NULL);
			}
			else
			{
				wait(0);
				 if(fork()==0)
                       		 {
                               		printf("**** child4 ls**\n");
					printf("\n");
                                	execlp("ps","ps",NULL);
					printf("\n");
                       		 }
				 else
				 {
					 wait(0);
					printf("In Parent..\n");
				 }
			}
		}
	}
}
