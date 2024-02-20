#include<stdio.h>
int a=10; //global variable
int sum(int);
int main()
{
    int b=20;                   //local variable
    a++;                        //post increment
    sum(a);                     // function passing
    printf("b=%d\n",b);         //printing output

    printf("A++=%d\n",a); 
}
int sum(int a)
{
    int c; //local variable
   
    //a++;   
    c=a+a;  // assisnment
a++;
    printf("a=%d \t",a); // output

    printf("c=%d\n",c); // c value

    printf("A=%d\n",a); 
    a++; //
}