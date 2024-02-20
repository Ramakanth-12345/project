#include<stdio.h>
void add(int *i)
{
	*i++;
}
void sub(int j)
{
	--j;
}
int main()
{
	int i=2,j=3;
	//add(&i);
	//sub(j);
	printf("calref %d\n",add(&i));
	printf("calval %d \n",sub(j));

}
