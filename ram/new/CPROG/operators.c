// Set, Clear and Toggle the corresponding bit without affecting other bits.
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int arr[MAX];
int k;
int set(int a,int bit)
{
    int j;
    j=arr[a];
    if((a>=0 && a<=k)&&(bit>=0 && bit<32))
    {
        printf("before setting %d\n",j);
        j=j|(1<<bit);
        printf("after setting %d\n",j);
    }
    else
    return 0;
    if(((j>>bit)&1)==1)
    return 1;
}
int clear(int a,int bit)
{
    int j;
    j=arr[a];
    if((a>=0 && a<=k)&&(bit>=0 && bit<32))
    {
        printf("before clear %d\n",j);
        j=j|(1<<bit);
        printf("after clear  %d\n",j);
    }
    else
    return 0;
    if(((j>>bit)&1)==1)
    return 1;
}
int toggle(int a,int bit)
{
    int j;
    j=arr[a];
    if((a>=0 && a<=k)&&(bit>=0 && bit<32))
    {
        printf("before toggle %d\n",j);
        j=j^(1<<bit);
        printf("after toggle %d\n",j);
    }
    else
    return 0;
    if(((j>>bit)&1)==1)
    return 1;
}
int main()
{
    int n,bit,S,T,C,i;
    printf("enter the no.of elements\n");
while(1)
{
    scanf("%d",&k);
    if(k>0 && k<=MAX)
    {
    printf("enter the array elements\n");
    for(i=0;i<k;i++)
    {
        scanf("%d",&arr[i]);
    }
        printf("enter the bit pos\n");
        scanf("%d",&bit);
        if(bit<=31 && bit>=0)
        {
         printf("enter the index no.\n");
        scanf("%d",&n);
        if(n<10 && n>=0)
        {
        S=set(n,bit);
        C=clear(n,bit);
        T=toggle(n,bit);
        }
        else
        {
            printf("enter correct index\n");
            return 0;
        }
        
    }
    else
    {
    printf("size excedded\n");
    return 0;
    }
    printf("%d\n",S);
    printf("%d\n",C);
    printf("%d\n",T);
    }
    else
    {
        printf("size is excedded\n");
        return 0;
    }
}
}
