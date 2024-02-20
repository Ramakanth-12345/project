#include<stdio.h>
#include<stdlib.h>
#define MAX 30
#define min 10
char s[10][30];
int i,j,n;
struct bill
{
	char *data;
	struct bill *prev,*link;	
}*head,*tail;
struct bill *append(char *s)
{
	printf("hu\n");
	struct bill *newnode=NULL;//*temp=NULL;
	newnode=(struct bill *)malloc(sizeof(struct bill));
	newnode->data=*s;
	newnode->link=head;
	if(head==NULL)
	{
	head=tail=newnode;
	head->link=head;
	head->prev=head;
	}
	else
	{
		tail->link=newnode;
		newnode->prev=tail;
		newnode->link=head;
		head->prev=newnode;
		tail=newnode;
	//	while(temp->link)
		//{
		//	temp=temp->link;
	//	}
		//temp->link=newnode;
		//newnode->prev=temp;
	//	newnode->link=p;
		//printf("kkkk\n");
	}
	//removechar(&p,n);
}
void display()
{
	printf("jk\n");
	struct bill *temp=NULL;
	if(head==NULL)
	{
	printf("list is empty\n");
	}
	else
	{
		temp=head;
		while(temp->link!=tail->link)
		{
			printf("1:\n");
			printf("%s",temp->data);
			temp=temp->link;
		}
	}
}
int main()
{
	struct bill *head=NULL,*last;
	printf("enter the no of strings\n");
	scanf("%d",&n);
	if(n<=min)
	{
		for(i=0;i<n;i++)
		{
			//for(j=0;j<=MAX;j++)
			//{
				printf("enter the string:\n");
				scanf("%s",s[i]);
			//}
			head=append(s[i]);
		}
		display();
	}
	else
	printf("size is excedded\n");
}

