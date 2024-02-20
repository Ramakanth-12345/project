 //Write an API to pass an array by reference and by value.
#include<stdio.h>
#include<stdlib.h>

int array[] = {1,2,3};
int size=sizeof (array)/sizeof (array[0]);
void function(int *array)
{
    array[0] = 4;
    array[1] = 5;
    array[2] = 6;   
}
void fun(int array[],int size)
{
	int i;
	int arr[size];
	for(i=0;i<size;i++)
	{
	arr[i++]=array[i];
	}
}
int main()
{
	int i;
	 fun(array,size);
	   printf("value:%d %d %d\n",array[0],array[1],array[2]);
    function(array);
    printf("ref:%d %d %d\n",array[0],array[1],array[2]);
}
