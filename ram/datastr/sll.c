#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[30];
	int roll;
	struct student *next;
};
struct student* addfirst(struct student *head)
{
	struct student *newnode=NULL;
	newnode=calloc(1,sizeof(struct student));
	if(newnode==NULL)
	{
		printf("node is not created\n");
	}
	else
	{
		printf("enter the name\n");
		scanf("%s",newnode->name);
		printf("Enter the roll\n");
		scanf("%d",&newnode->roll);
		newnode->next=head;
		head=newnode;
	}
	return head;
}
struct student* addlast(struct student *head)
{
	struct student *newnode=NULL,*temp=NULL;
	newnode=calloc(1,sizeof(struct student));
	if(newnode==NULL)
	{
		printf("node is not created\n");
	}
	else
	{
		printf("enter the name\n");
		scanf("%s",newnode->name);
		printf("enter the roll\n");
		scanf("%d",&newnode->roll);
		if(head==NULL)
		{
			//newnode->next=head;
			head=newnode;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
		}
	}
	return head;
}
struct student* dellast(struct student *ptr)
{
	struct student* temp=NULL;
	if(ptr==NULL)
	{
		printf("List is Empty\n");
	}
	else if(ptr->next=NULL)
	{
		free(ptr);
		ptr=NULL;
	}
	else
	{
		temp=ptr;
		while(temp->next->next)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
	return ptr;
}
void Display(struct student *head)
{
	if(head==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		while(head)
		{
			printf("%s %d\n",head->name,head->roll);
			head=head->next;
		}
	}
}
struct student randomdel(struct student *head)
{
	struct student *ptr,*ptr1;
	int loc,i;
	printf("Enter the loc\n");
	scanf("%d",&loc);
	ptr=head;
	for(i=0;i<loc;i++)
	{
		ptr1=ptr;
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("cannot be deleted\n");

		}
	}
	ptr1->next=ptr->next;
	free(ptr);
	printf("Deleted node is %d\n",loc+1);

}
int main()
{
	struct student *head=NULL;
	int choice;
	while(1)
	{
		printf("1.add first\n 2.addlast\n 3.dellast\n 4.Display\n 5.random del\n 6.exit\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:head=addfirst(head);
			       break;
			case 2:head=addlast(head);
				break;
			case 3:dellast(head);
			       break;
			case 4:Display(head);
			       break;
			case 5:randomdel(head);
			       break;
			case 6:exit(0);
		}
	}

}
