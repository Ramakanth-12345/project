#include"header.h"
main()
{
	printf("Hello....%d\n",getpid());
	sleep(10);
	raise(SIGSEGV);
}
