#include"header.h"
int main()
{
	int p[2];
	pipe(p);
	perror("pipe");
	if(fork()==0)
	{
		close(p[1]);
	}
	else
		close(p[0]);
}
