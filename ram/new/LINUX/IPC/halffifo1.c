#include"header.h"
int main()
{
	int fdr,fdw;
	char a[100],b[100];
	fdr=open("fifohd1",O_RDWR);
	fdw=open("fifohd2",O_RDWR);
	while(1)
	{
		bzero(b,sizeof(b));
		read(fdr,b,sizeof(b));
		printf("\t\tfrom      Banglore......\n\t\t%s\n\t\t******\n",b);
		printf("you\n");
                scanf("%[^\n]",a);
                write(fdw,a,strlen(a)+1);

	}

}
