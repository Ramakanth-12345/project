#include"headers.h"
pthread_t tid1,tid2;
volatile int cnt=1;
//using volatile, the use of cnt variable,
//can't be optimized. 

void *f1(void *p)
{
	unsigned long int i;
	printf("Entered thread1..f1\n");
	///////////////////////////////
	for(i=0;i<3000000000;i++)
		cnt++;
	/////////////////////////////////////
	printf("exiting thread1...f1\n");
	pthread_exit(NULL);
}
void *f2(void *p)
{
	unsigned long int i;
	printf("Entered thread2..f2\n");
	/////////////////////////////////
	for(i=0;i<3000000000;i++)
		cnt--;
	/////////////////////////////
	printf("exiting thread2...f2\n");
	pthread_exit(NULL);
}

int main()
{
	pthread_create(&tid1,NULL,f1,NULL);
	pthread_create(&tid2,NULL,f2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("main...cnt=%lu\n",cnt);
}
