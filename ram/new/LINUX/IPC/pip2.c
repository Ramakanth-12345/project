#include"header.h"
void isr(int n)
{
	printf("In ISR%d...%s\n",n,strsignal(n));
	
}
int main()
{
	int p[2],a=20;
	pipe(p);
	perror("pipe");
	signal(SIGPIPE,isr);
	close(p[0]);
	write(p[1],&a,4);
	perror("write");
	//printf("write returns %d\n",a);
}
