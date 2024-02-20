#include"../header/main.h"
int sub(int a,int b)
{
	int c;
	if(a>b)
	{
		c=a-b;
		return c;
	}
	else
		return (c=b-a);
}
