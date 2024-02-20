#include"headers.h"
int main(int argc,char **argv)
{
	struct utimbuf buf;
	buf.actime=buf.modtime=time(NULL)-3600*24;
if(utime(argv[1],&buf)==-1)
	perror("");
else
	printf("timestamp updated\n");

}
