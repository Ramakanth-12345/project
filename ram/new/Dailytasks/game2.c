#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data[20];
    struct node* next;
};



struct node* addatbeg(char data[])
{
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    strcpy(temp->data,data);
    temp->next=temp;
    return temp;
}



struct node* addatend(struct node* tail,char data[])
{
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
   //temp->next=NULL;
    strcpy(temp->data,data);
    temp->next=tail->next;
    tail->next=temp;
    tail=tail->next;
    return tail;
}



struct node* createlist(struct node* tail)
{
    char data[20];
    int i,n;
    printf("enter the no.of nodes:\n");
    scanf("%d",&n);
    if(n==0)
    return tail;
    printf("enter the name:\n");
    scanf("%s",data);
    tail=addatbeg(data);
    for(i=1;i<n;i++)
    {
        printf("enter the name %d:\n");
        scanf("%s",data);
        tail=addatend(tail,data);
    }
    return tail;
}



void display(struct node* tail)
{
    struct node* temp=NULL;
    if(tail==NULL)
    {
        printf("list is empty:\n");
    }
    else
    {
        temp=tail->next;
        do
        {
            printf("%s\n",temp->data);
            temp=temp->next;
        }while(temp!=tail->next);
    }
}



void searchdeletechar(struct node* tail)
{
    struct node* temp=tail->next;
    struct node *temp1,*temp2;
    char ch;
    int nel,i,nodecnt,chcnt;
    //int p,q,r;
    nel=(int)strlen(temp->data);
    for(i=0;i<nel;i++)
    {
        nodecnt=0,chcnt=0;
        ch=temp->data[i];
        temp1=tail->next;//common char find
        do{
            if(strchr(temp1->data,ch))
            chcnt++;
            nodecnt++;
            temp1=temp1->next;
          }while(temp1!=tail->next);
        
         temp2=tail->next;//delete char
         if(nodecnt==chcnt)
         {
             do{
             //    printf("delete common character:\n");
                printf("%s ",temp2->data);
                 int i,j,r=0;
         //    r=0;
                 for(i=0,j=0;i<strlen(temp2->data);i++,j++)
                 {
                     if((temp2->data[i]==ch) && (r!=1) )
                     {
                         i++;
                         r=1;//single char delete only
                     }
                     temp2->data[j]=temp2->data[i];
                 }
                 temp2->data[j]='\0';
                 temp2 =temp2->next;
              }while(temp2!=tail->next);
             // printf("%s",temp2->data);
         }
   }
}



int length(struct node* tail)
{
    int len=0;
    struct node* temp=tail->next;
    do{
        len=len+(int)strlen(temp->data);
        temp=temp->next;
      }while(temp!=tail->next);
      
      return len;
}



struct node* billpayer(struct node* tail)
{
    int len,cnt;
    searchdeletechar(tail);
    len=length(tail);
    struct node* temp=tail->next;
    struct node* temp_pre;
    cnt=1;
    do{
        if(cnt==len)
          {
          temp_pre->next=temp->next;
          free(temp);
          temp=temp_pre;
          cnt=0;    
          }
        cnt++;
        temp_pre=temp;
        temp=temp->next;
        }while(temp!=temp->next);
     
     return temp;
    
}
int main()
{
    struct node *tail=NULL;
    tail=createlist(tail);
    printf("before list:\n");
    display(tail);
    
    tail=billpayer(tail);
    printf("after delete list:\n");
    display(tail);
}
