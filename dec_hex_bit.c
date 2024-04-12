#include<stdio.h>
#include<math.h>
int main()
{
    int num=122,i,r=0,t=0,j=0,l=0;
    char hex[20];
    //printf("Enter the num\n");
    //scanf("%d",&num);
    /*for(i=7;i>=0;i--)
    {
        if(((num>>i)&1)==1)
        printf("1 ");
        else
        printf("0 ");
    }
    printf("\n");*/
    for(i=7;i>=0;i--)
    {
        r=((num>>i)&1); //0 1 1 1 1 0 1 0
        printf("j=%d ",j); 
        if(r==1) //1 
        t=t+pow(2,j);//0+1
        else
        t=t+r;//0
        j++;//1
        printf("t1=%d ",t);//1
        if(j==4)
        {
            printf("j=%d\t",j);
            if(t<10)
            t=t+48;
            else
            t=t+55;
            printf("t=%d\n",t);
            hex[l++]=t;
            j=0;
            t=0;
        }
    }
    for(i=l-1;i>=0;i--)
    {
        printf("%c ",hex[i]);
    }
}