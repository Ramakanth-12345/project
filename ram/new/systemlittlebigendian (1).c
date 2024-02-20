//1)Write an API to determine the endianness of your system.
#include<stdio.h>

struct SbitField
{
	unsigned int BIT1:8;
	unsigned int BIT2:8;
	unsigned int BIT3:8;
	unsigned int BIT4:8;
};

union UbitField
{
	unsigned int num;
	struct SbitField num2;
};

int main()
{
	unsigned int a;
	printf("Enter the Non-zero value:\n");
	scanf("%d",&a);
		if(a==0)
		{
			printf("enter value is not a non-zero\n");
		}
	
	union UbitField temp;
	temp.num=a;
	char *ptr;
	ptr=(char *)&a;
	
	if(ptr[0]==(char)temp.num2.BIT1)
		printf("Machine is Little endian:\n");
	else
		printf("Machine is Big endian:\n");
	
	printf("%d %d %d %d\n",temp.num2.BIT1,temp.num2.BIT2,temp.num2.BIT3,temp.num2.BIT4);
}
