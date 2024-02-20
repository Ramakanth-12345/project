#include"header.h"
main()
{
	int p[2];
	pipe(p);
//	printf("p[0]=%d read end\np[1]=%d write end\n",p[0],p[1]);
	perror("pipe");
}
