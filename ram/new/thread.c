#include"header.h"
//#define MAX 
int i,j,k,MAX;
sem_t sem1,sem2,sem3;
void *f1(void *p)
{
	for(i=0;i<=MAX-2;i++)
	{
		sem_wait(&sem1);
		if(i==0)
			printf("t1:%d",i);
		else
			printf("\nt1:%d",i+=2);
		sem_post(&sem2);
	}
}
void *f2(void *p)
{
        for(j=1;j<=MAX-2;j++)
        {
                sem_wait(&sem2);
                if(j==1)
                        printf("\nt2:%d",j);
                else
                        printf("\nt2:%d",j+=2);
                sem_post(&sem3);

        }
}
void *f3(void *p)
{
        for(k=2;k<=MAX-2;k++)
        {
	  sem_wait(&sem3);
                if(k==2)
                        printf("\nt3:%d",k);
                else
                        printf("\nt3:%d",k+=2);
                sem_post(&sem1);
	
        }
	printf("\n");
}
int main()
{
	printf("enter the MAX\n");
	scanf("%d",&MAX);
	pthread_t t1,t2,t3;
	sem_init(&sem1,0,1);
	sem_init(&sem2,0,0);
	sem_init(&sem3,0,0);

	pthread_create(&t1,NULL,f1,(void*)NULL);
	pthread_create(&t2,NULL,f2,(void*)NULL);
	pthread_create(&t3,NULL,f3,(void*)NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	return 0;
}
