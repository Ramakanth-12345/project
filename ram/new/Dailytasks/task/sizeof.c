 //find the size of a variable and data type without using sizeof operator
#include<stdio.h>
#include<stdlib.h>
#define sizeof_var(var) ((size_t)(&(var)+1)-(size_t)(&(var))) 
int  main()
{
	char a;
	short int b;
	int c;
	float d;
	double e;
	long long int f;
	printf("size of char:%d\n",sizeof_var(a));
	printf("size of short int:%d\n",sizeof_var(b));
	printf("size of int:%d\n",sizeof_var(c));
	printf("size of float:%d\n",sizeof_var(d));
	printf("size of double:%d\n",sizeof_var(e));
	printf("size of long long int:%d\n",sizeof_var(f));
}
