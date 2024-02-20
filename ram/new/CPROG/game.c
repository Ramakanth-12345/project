#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30
int i,count;
struct bill
{
	char *name;
	struct bill *link,*prev;
}*head,*tail;
char *removechar(char *s1,char *s2,char *s3,char *s4)
{
	char ch='a',*p,*q,*r,*s;
	while(ch<='z')
	{
	//	printf("kk");
		if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
		{
		//	printf("kk1");
			p=strchr(s1,ch);
			//printf("kk2");
			//printf("%c",*p);
			if(p!=NULL && *p==ch)
			{
				
				q=strchr(s2,ch);
				//	printf("%c",*q);
				if(q!=NULL && *q==ch)
				{
				
					r=strchr(s3,ch);
						//printf("%c",*r);
					if(r!=NULL && *r==ch)
					{
					
						s=strchr(s4,ch);
							//printf("%c",*s);
						if(s!=NULL && *s==ch)
						{
							memmove(p,p+1,strlen(p+1)+1);
							memmove(q,q+1,strlen(q+1)+1);
							memmove(r,r+1,strlen(r+1)+1);
							memmove(s,s+1,strlen(s+1)+1);
						}
					}
				}
			}
		}
		ch++;
	}
	//printf("%s %s %s %s\n",s1,s2,s3,s4);
	i=strlen(s1)+strlen(s2)+strlen(s3)+strlen(s4);
	printf("%d\n",i);
	append(s1);
	append(s2);
	append(s3);
	append(s4);
	display();
	delete();/
	display();
}
void append(char *s)
{
	//printf("hu\n");
	struct bill *newnode=NULL;
	//head=NULL;
	newnode=(struct bill *)malloc(sizeof(struct bill));
	newnode->name=s;
	newnode->link=head;
	if(head==NULL)
	{
		//printf("hi1ii\n");
	head=tail=newnode;
	head->link=head;
	head->prev=head;
	}
	else
	{
		//printf("hi\n");
		tail->link=newnode;
		newnode->prev=tail;
		newnode->link=head;
		head->prev=newnode;
		tail=newnode;
	}
}
void display()
{
	//printf("jk\n");
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
			//printf("1:\n");
			printf("%s\n",temp->name);
			temp=temp->link;
		}
		printf("%s\n",temp->name);
	}
}
/*void Delete()
{
	struct bill*temp=NULL;
	while(1)
	{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	temp=head;
	//count++;
	else 
	{
		
	count++;
	if((temp->link && temp->prev)==tail)
	{
		printf("only one is present\n");
		printf("%s\n",head->name);			
	}
	else
	{
		count++;
		if(temp->link!=head)
		{
			
		}
			
	}
	}
	}
}*/
void delete()
{
	struct bill *temp=NULL,*last,*prev;
	temp=head;   
	int c,j;
   	if(temp==0)
 	   {
        printf("no record found\n");
        return ;
   		}
    	c=i;
     	if(c==1)
		{
			head=0;
			free(temp);
			return;
		}
		for(j=1;j<=c;j++)
		{	
    		if(i==j)
    		{
        		if(i==1)
        		{
        			last=head;
        			while(last->link != head)    
        			last=last->link;
        	        head=temp->link;
        			last->link=head;
    			}
   				 else
   				 	{
    				prev->link=temp->link;
    				free(temp);
    				return;
    				}
			}
				prev=temp;
				temp=temp->link;
		}
		
}
int main()
{
	struct bill *head=NULL;
	char s1[MAX],s2[MAX],s3[MAX],s4[MAX];
	printf("enter the strings\n");
	gets(s1);
	gets(s2);
	gets(s3);
	gets(s4);
	removechar(s1,s2,s3,s4);
	//printf("%s %s %s %s\n",s1,s2,s3,s4);
	
}
