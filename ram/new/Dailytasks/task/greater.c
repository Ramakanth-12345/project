#include<stdio.h>
#define lag(a,b) a>b?a:b
int  main()
{
	int a,b;
	printf("enter the numbers\n");
	scanf("%d %d",&a,&b);
	printf("larger:%d\n",(lag(a,b)));
}
