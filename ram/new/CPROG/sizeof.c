//finding size of  a variable and datatype without using the sizeof()


#include<stdio.h>
#define var_size(i) (char*)(&i+1)-(char*)(&i)
int main()
{
char i =1;
short j=1;
int k=1;
long int l=1;
long long int m=1;
float n=1;
double o=1;
printf("char=%d\n",var_size(i));
printf("short=%d\n",var_size(j));
printf("int=%d\n",var_size(k));
printf("long int=%d\n",var_size(l));
printf("long long int=%d\n",var_size(m));
printf("float=%d\n",var_size(n));
printf("double=%d\n",var_size(o));
}


