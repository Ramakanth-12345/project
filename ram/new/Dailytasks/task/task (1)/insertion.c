#include<stdio.h>
int main()
{
	int i,j,k,size,min;
	printf("enter the no.of elements\n");
	scanf("%d",&size);
	int arr[size],temp;
	size=sizeof(arr)/sizeof(arr[0]);
	printf("enter the elements\n");
	for(i=0;i<size;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<size;i++)
	{
		min=arr[i];
			k=i;
		//for(j=i;j>=1;j--)insertion
		for(j=i+1;j<size;j++)
		{
			
//			if(arr[j]>arr[j-1])
			//:if(arr[i]<arr[j])
			//{
				min=arr[j];
					k=j;
				
			}
				temp=arr[j];
				arr[j]=arr[k];
				arr[k]=temp;	
	//	}		
	}
	printf("after sorting\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);	
	}	
}
