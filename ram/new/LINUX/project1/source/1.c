#include"../header/main.h"
int main()
{
	int a,b;
	printf("Enter the num\n");
	scanf("%d %d",&a,&b);
	printf("sum=%d\n",sum(a,b));
	printf("sub=%d\n",sub(a,b));
	Inc(a,b);
	printf("a=%d b=%d\n",a,b);
}
