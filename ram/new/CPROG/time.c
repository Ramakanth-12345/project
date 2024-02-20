#include"headers.h"
int main()
{
	char dateString[20],timeString[20];
	struct tm *tmPtr;
	time_t t;
	while(1)
	{
	time(&t);//fetches the kernel's time.
	//measured in seconds since epoch
//	printf("%u\n",(unsigned int)t);
	tmPtr=localtime(&t);
	strftime(dateString,20,"%F",tmPtr);
	strftime(timeString,20,"%T",tmPtr);
	printf("%s %s\n",dateString,timeString);
	sleep(1);
	system("clear");
	}
	exit(0);
}
