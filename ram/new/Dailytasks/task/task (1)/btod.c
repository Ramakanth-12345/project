#include<stdio.h>
int main()
{
	int n,f=1,sum=0,rem;
	scanf("%d",&n);
	while(n)
	{
		//rem=n%10;//binary to decimal
		//rem=n%2;//decimal to binary
		rem=n%8;//decimal to octal
		sum=sum+(rem*f);
		f=f*8;//decimal to octal
		//f=f*10;//decimal to binary
		//f=f*2;//binary to decimal
		//n=n/10;//binary to decimal
		//n=n/2;//decimal to binary
		n=n/8;//decimal to octal
		
	}
	printf("%d",sum);
}
