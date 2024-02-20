#include"header.h"
int main()
{
	int p[2];
	pipe(p);
	if(fork()==0)
	{
		close(p[0]);
		close(1);
		dup(p[1]);
		execlp("ls","ls",(char*)NULL);
	}
	else
	{
		if(fork()==0)
      		  {
                	close(p[1]);
                       	dup2(p[0],0);
                	execlp("wc","wc","-l",(char*)NULL);
        	  }
		else
		{
			close(p[0]);
			close(p[1]);
			wait(0);
			wait(0);
		}

	}
}

