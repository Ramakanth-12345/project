//3.write an API to pass an array by reference and by value.
#include<stdio.h>
struct Array
{
	int arr[10];
};

void display1(struct Array temp)
{
	int *ptr=temp.arr;
	int i;
	printf("before modification():\n");
	for(i=0;i<10;i++)//display array elements
	printf("%d ",ptr[i]);
	printf("\n");

	for(i=0;i<10;i++)//modify the array
		ptr[i]=200;
	printf("\nAfter modifiaction():\n");
	for(i=0;i<10;i++)
	printf("%d ",ptr[i]);

}

int main()
{
	//int arr[10]={56,32,6,89,13,59,432,35,67,98};
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int i;
	struct Array obj;
	for(i=0;i<10;i++)
	obj.arr[i]=10;

	 
	display1(obj);//passing elements
	//printf("after:%d\n",arr[i]);
	
	printf("\nAfter calling modify():\n");
	for(i=0;i<10;i++)
	{
		printf(" %d ",obj.arr[i]);
	}
	printf("\n");
}
