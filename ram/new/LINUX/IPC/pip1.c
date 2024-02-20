#include"header.h"
int main()
{
	int p[2],a=20;
	pipe(p);
	perror("pipe");
	close(p[1]);
	a=read(p[0],&a,4);
	perror("read");
	printf("read returns %d\n",a);
}
