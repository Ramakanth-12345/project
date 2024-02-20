#include"header.h"
main()
{
	int i=1;
	printf("Hi...\n");
	alarm(5);
	printf("Hello..\n");
	while(1)
	{
		printf("i=%d\n",i++);
		sleep(1);
	}
}
