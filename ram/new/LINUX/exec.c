#include<stdio.h>
#include<unistd.h>
main()
{
	printf("In Exce1..PID %d PPID %d\n",getpid(),getppid());
	//execl("./p1.c","p1",NULL);
	system("./p1");
	printf("thanks\n");
}
