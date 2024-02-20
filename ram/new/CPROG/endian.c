//checking whether the system of little endian or big endian
#include<stdio.h>
int endian(int n)
{
	char *p;
	p=&n;
	if(*p==1)
	return 1;
	else 
	return 0;
}
int main()
{
	int n;
	//char *p;	
	printf("enter the number\n");
	scanf("%d",&n);
	//p=&n;
	printf("%d\n",endian(n));
	if(n==1)
	printf("big endian\n");
	else
	printf("little endian\n");
}
