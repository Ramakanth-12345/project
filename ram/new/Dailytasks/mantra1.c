#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct special_mantra
{
    int data;
    struct special_mantra *link;
};
void append(struct special_mantra ** ,int );
void display_data(struct special_mantra *);
void sort(struct special_mantra **q,int ,int );
void main()
{
int n,l,h;
struct special_mantra *hptr=0;
printf("enter the maximum no.\n");
scanf("%d",&n);
append(&hptr,n);
display_data(hptr);        
printf("enter the l and h\n");
scanf("%d%d",&l,&h);
sort(&hptr,l,h);
display_data(hptr);    
}
void append(struct special_mantra **q ,int n )
{
struct special_mantra *head,*temp;
while(n)
{
head=malloc(sizeof(struct special_mantra)*n);
printf("enter the no.\n");
scanf("%d",&head->data);
if(*q==0)
{
    head->link=*q;
    *q=head;
}
    else
    {
        temp=*q;
        while(temp->link)
    temp=temp->link;
    temp->link=head;
    head->link=0;
    }
n--;
}
}
void display_data(struct special_mantra *q)
{
    while(q)
    {
        printf("%d ",q->data);
        q=q->link;
    }
    printf("\n");
}



/*void sort(struct special_mantra **q,int l,int h)
{
int i,j,c=5;
struct special_mantra *p1,*p2,temp;
if((*q)==0)    
    {
    printf("no record found\n");
    return;
    }




p1=*q;
for(i=0;i<c-1;i++)
{
        p2=p1->link;
    for(j=0;j<c-1-i;j++)
    {
        if(p1->data > p2->data)
    {
            temp.data=p1->data;
        p1->data =p2->data;
        p2->data =temp.data;
    }
        }
        p2=p2->link;
    }
    p1=p1->link;
    */

