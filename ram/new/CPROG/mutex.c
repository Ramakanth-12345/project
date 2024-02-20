#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define THREAD_LIMIT  3
pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;
int PRINT_MAX = 500;
pthread_cond_t  cond[THREAD_LIMIT];//  = PTHREAD_COND_INITIALIZER;

struct thread_arg
{
    int index;
    pthread_cond_t *waitCond;
    pthread_cond_t *signalCond;
};

void* threadFun(void* pArg)
{
    struct thread_arg *pThreadArg = (struct thread_arg *)pArg;
    int i=pThreadArg->index, rValue;
    for(;i< PRINT_MAX;i += THREAD_LIMIT)
    {
        rValue = pthread_mutex_lock(&mutex);
        printf("thread index = %d  value = %d \n",(pThreadArg->index+1), i);

        rValue = pthread_cond_signal(pThreadArg->signalCond);
        //wait for turn
        while( pthread_cond_wait(pThreadArg->waitCond, &mutex) != 0 )
        {}
        rValue = pthread_mutex_unlock(&mutex);
    }

    rValue = pthread_cond_signal(pThreadArg->signalCond);
    return NULL;    
}


int main()
{
	int i;
    pthread_t ThreadId[THREAD_LIMIT];
    struct thread_arg ThreadArg[THREAD_LIMIT];

    for (i =0; i< THREAD_LIMIT ; i++)
        pthread_cond_init(&cond[i], NULL);

    for ( i =0; i< THREAD_LIMIT ; i++)
    {
        ThreadArg[i].index = i;
        ThreadArg[i].waitCond = &cond[i];
        if (i == THREAD_LIMIT-1)
            ThreadArg[i].signalCond = &cond[0];
        else
            ThreadArg[i].signalCond = &cond[i+1];

        printf("starting Thread %d \n",i+1);
        pthread_create(&ThreadId[i], NULL, &threadFun,(void*)&ThreadArg[i]);
        usleep(500);
    }
    for ( i =0; i< THREAD_LIMIT ; i++)
        pthread_join(ThreadId[i],NULL);

    return 0;
}
