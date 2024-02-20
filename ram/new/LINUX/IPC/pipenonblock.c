#include"header.h"
int main()
{
	int p[2],c;
	char ch='a';
	pipe2(p,O_NONBLOCK);
	c=0;
	while(write(p[1],&ch,1)!=-1)
	{
		c++;
	}
	printf("size of pipe is %d\n",c);

}
