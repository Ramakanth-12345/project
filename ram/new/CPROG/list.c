#include"headers.h"
int main(int argc,char **argv)
{
	struct dirent  *ptr;
	DIR *dp;
	if(argc<2)
	dp=opendir("./");
	else
	dp=opendir(argv[1]);

	while(ptr=readdir(dp))
		printf("%s...%u\n",ptr->d_name,ptr->d_ino);

	closedir(dp);
return 0;
}
