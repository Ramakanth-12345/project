#include<stdio.h>
void summ(int *x,int *y)
{
	*x=1+*x;
	*y=1+*y;
}
void sum(int a,int b)
{
	a=1+a;
	b=1+b;
}
int main()
{
	int n1,n2;
	printf("enter the numbers\n");
	scanf("%d %d",&n1,&n2);
	sum(n1,n2);
	printf("%d %d\n",n1,n2);
	summ(&n1,&n2);	
	printf("%d %d",n1,n2);
}
