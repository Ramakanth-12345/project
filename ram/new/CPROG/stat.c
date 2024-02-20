#include"headers.h"
int main(int argc,char **argv)
{	
	struct stat buf;
	if(stat(argv[1],&buf)==-1){
		perror("stat");return 0;}

	printf("%lu\n",(unsigned long)buf.st_size);
	printf("%u\n",(unsigned int)buf.st_mtime);
}
