#include"header.h"
int main()
{
	int fd;
	fd=dup(2);
	printf("fd=%d\n",dup(1));
	write(dup(2),"hello\n",4);
}
