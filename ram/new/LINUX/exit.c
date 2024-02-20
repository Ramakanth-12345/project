#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void abc(void)
{
	printf("IN abc..\n");
}
void def(void)
{
	printf("IN def..\n");
}
int main()
{
	atexit(abc);
	atexit(def);
	printf("Hello..\n");
	sleep(5);
	_exit(0);
}
