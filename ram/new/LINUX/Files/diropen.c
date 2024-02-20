#include"header.h"
main()
{
	struct dirent *p;
	DIR *dp;
	dp=opendir(".");
	if(dp==0)
	{
		perror("opendir");
		return;
	}
	while(p=readdir(dp))
	{
		printf("%s\n",p->d_name);
	}
}
