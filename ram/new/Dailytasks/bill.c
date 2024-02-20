#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30
#define min 10
char s[min][MAX];
char ch;
struct bill
{
char *data;
struct bill *prev,*link;	
};
void display(struct bill *p)
{
	struct bill *temp=NULL;
	
	if(p==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		temp=p;
		while(temp!=p)
		{
			printf("%s\n",temp->data);
			temp=temp->link;	
		}
	}
}
struct bill *append(struct bill *p,char *n)
{
	//printf("hu\n");
	struct bill *newnode=NULL,*temp=NULL;
	newnode=(struct bill *)malloc(sizeof(struct bill));
	newnode->data=n;
	newnode->link=p;
	if(p==NULL)
	{
	p=newnode;
	}
	else
	{
		temp=p;
		while(temp->link)
		{
			temp=temp->link;
		}
		temp->link=newnode;
		newnode->prev=temp;
		newnode->link=p;
	}
	//removechar(&p,n);
}

/*char removechar(char *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
	ch='A';
	if((ch>='A'&& ch<='Z')||(ch>='a'&&ch<='z'))
	{
		if(strchr(data->link,ch)==(p->link))
		&&(strchr(q[i],ch)==ch)&&(strchr(r[i],ch)==ch)))
		{
			memove(p,p+1,strlen(p+1)+1);
			memove(q,q+1,strlen(q+1)+1);
			memove(r,r+1,strlen(r+1)+1);
		}		
	}
	ch=ch+1;
	}
	//printf("%s %s %s",p,q,r);
}*/
int main()
{
	struct bill *head=NULL;
	int i,n;
	//char s[min][MAX];
	printf("enter min no of strings\n");
	scanf("%d",&n);
	if(n<=min)
	{
	
	for(i=0;i<n;i++)
	{
		printf("enter the strings\n");
	scanf("%s",s[i]);
	head=append(head,s[i]);
	}
	//head=removechar(s[i],n);
	display(head);
	}
	else
	printf("No of strings are more\n");	
}
