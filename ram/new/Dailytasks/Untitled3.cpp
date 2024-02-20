#include<stdio.h>
int convert(int i)
{
	int bit;
	for(bit=7;bit>=0;bit--)
	{
		printf("%d",(i>>bit)&1);
	}
}
int converts(short i)
{
	int bit;
	for(bit=7;bit>=0;bit--)
	{
		printf("%d",(i>>bit)&1);
	}
}
int main()
{
	char *p,*q;
	int i,j;
	short k;
	printf("enter the num\n");
	scanf("%d",&j);
	printf("enter the num\n");
	scanf("%d",&k);
	p=&j;
	for(i=3;i>=0;i--)
	convert(*(p+i));
	q=&k;
	for(i=1;i>=0;i--)
	converts(*(q+i));	
}
