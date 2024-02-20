//Write a Macro like function to multiply 2 numbers.
#include<stdio.h>
#include<stdlib.h>
#define mul(a,b,c) a*b*c
int main()
{
	int a,b,c;
	printf("enter the num\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("mul:%d\n",mul(a,b,c));
}
