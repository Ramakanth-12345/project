#include<stdio.h>
//#inlude<stdlib.h>
#define MAX 15
struct mantra
{
	int data;
	struct mantra *link;
};
/*void append(struct mantra **p,int n)
{
	struct mantra *newnode=NULL;
	newnode=(struct mantra *)malloc(sizeof(struct mantra));
	newnode->data=n;
	newnode->link=*p;
	*p=newnode;
}
void Display(struct mantra *head)
{
	struct mantra *temp=NULL;
	temp=head;
	
	if(temp==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		printf("data displayed\n");
		while(temp!=NULL)
		{
		printf("%d\n",temp->data);
		temp=temp->link;
		}
	}
//	printf("\n");
}
/*void Display(struct mantra* head)
{
    //struct mantra *temp = head;
    while (head != NULL) 
	{
        printf("%d ", head->data);
        head= head->next;
    }
}*/
/*struct mantra *reverse(struct mantra* head)
{
    struct mantra *prev = NULL,*next=NULL;
    struct mantra *current=NULL;
   // *current = head;
   printf("After reverse\n");
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else if(head->link==NULL)
	{
		printf("it has only single node\n");
	}
	else
	{
      next=head;
      while(next)
      {
 	   prev = current;
    	current = next;
        next=next->link;
        current->link=prev;
    	}
    	head = current;
     }
}
struct mantra *ascend(struct mantra* head)
{
    struct mantra *prev = NULL,*next=NULL;
    int temp;
    //struct mantra *current=NULL;
   // *current = head;
   printf("After ascend\n");
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else if(head->link==NULL)
	{
		printf("it has only single node\n");
	}
	else
	{
       while(head!=NULL)
      {
      	next=head->link;
      	while(next!=NULL)
      	{
      		if(head->data > next->data)
      	{
		temp=head->data;
		head->data = next->data;
		next->data =temp;
    	}
    	next=next->link;
    	}
    	head=head->link;
     }
 }
}
/*void sort(struct special_mantra *head,int l,int h)
{
    struct special_mantra *temp=NULL;
    temp=head;
        if(temp==NULL)
        {
            printf("list is empty\n");
            return;
        }
        else if(l<h)
        {
            while(temp->link!=NULL)
            {
                while(l<=(temp->data) && h>=(temp->data))
                {
                    ascend(temp);
                    displaydata(temp);
                }
                temp=temp->link;
            }
        }
        else
        {
        head=descend(head);
        displaydata(head);
        //reverse(head);
        }
}*/
/*int getCount(struct mantra* head)
{
    int count = 0; // Initialize count
    struct mantra *cur = head; // Initialize current
    while (cur!= NULL)
	 {
        count++;
        cur=cur->link;
    }
    return count;
}*/
int main()
{
	struct mantra *head=NULL;
	int n,i,size;
	printf("enter the size\n");
	scanf("%d",&size);
	if(n<=MAX)
	{
		for(i=0;i<size;i++)
		{
			printf("enter the value\n");
			scanf("%d",&n);
			//append(&head,n);
		}
	//	Display(head);
		//head=reverse(head);
	//	Display(head);
		//sort(head,l,h);
		//ascend(head);
	//	Display(head);
		//printf("%d\n",getcount(head));
	}
	else 
	printf("size is too large\n");
}
