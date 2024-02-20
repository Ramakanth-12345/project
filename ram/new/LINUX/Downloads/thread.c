#include"headers.h"
pthread_t tid1,tid2;
int cnt=1;
pthread_mutex_t m1;
void *f1(void *p)
{
	unsigned long int i;
	printf("Entered thread1..f1\n");
	///////////////////////////////
	pthread_mutex_lock(&m1);
	printf("thread1:cnt=%lu\n",cnt);
	for(i=0;i<3000000000;i++)
		cnt++;
	printf("thread1...cnt=%lu\n",cnt);
	pthread_mutex_unlock(&m1);
	/////////////////////////////////////
	printf("exiting thread1...f1\n");
	pthread_exit(NULL);
}
void *f2(void *p)
{
	unsigned long int i;
	printf("Entered thread2..f2\n");
	/////////////////////////////////
	pthread_mutex_lock(&m1);
	printf("thread2:cnt=%lu\n",cnt);
	for(i=0;i<3000000000;i++)
		cnt--;
	printf("thread2...cnt=%lu\n",cnt);
	pthread_mutex_unlock(&m1);
	/////////////////////////////
	printf("exiting thread2...f2\n");
	pthread_exit(NULL);
}

int main()
{
	pthread_mutex_init(&m1,NULL);
	pthread_create(&tid1,NULL,f1,NULL);
	pthread_create(&tid2,NULL,f2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("main...cnt=%lu\n",cnt);
}
