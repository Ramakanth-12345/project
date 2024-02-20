#include"header.h"
main()
{
	int i;
	printf("hi..\n");
	i=alarm(10);
	printf("return alarm(10)\n");

	sleep(3);

	i=alarm(4);
	printf("return alarm(4)\n");
	sleep(2);

	i=alarm(0);
	printf("return alarm(0)\n");
	printf("hello..\n");
}
