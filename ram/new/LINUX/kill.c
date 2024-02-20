#include"header.h"
int main(int argc,char **argv)
{
	int r,sig;
	if(argc!=3)
	{
		printf("Usage:./mykill pid signum\n");
		return;
	}
	sig=atoi(argv[2]);
	r=kill(atoi(argv[1]),sig);
	if(sig!=0)
	{
		if(r==-1)
			perror("kill");
	}
	else
	{
		if(r==0)
		{
			printf("Process exists and we can send it a signal\n");
		}
		else
		{
			if(errno==EPERM)
				printf("Process Exists,No Permission to send signals\n");
			else if(errno==ESRCH)
				printf("Process does not exists\n");
			else
				perror("kill\n");
		}
	}
}
