#include<stdio.h>
#include<dlfcn.h>
main()
{
	int r,op,a,b;
	void *handler;
	int(*p)(int,int);
	printf("enter the num\n");
	scanf("%d %d",&a,&b);
	printf("enter your opt \n1:sum \n2:mul\n");
	scanf("%d",&op);
	
	handler=dlopen("./libxyz.so",RTLD_NOW);
	if(handler==0)
	{
		printf("%s\n",dlerror());
		return ;;
	}
	switch(op)
	{
		case 1:
			p=dlsym(handler,"sum");
			if(p==0)
			{
				printf("%s\n",dlerror());
				return;
			}
			r=(*p)(a,b);
			printf("%d\n",r);
			break;
		case 2:
			p=dlsym(handler,"mul");
                        if(p==0)
                        {
                                printf("%s\n",dlerror());
                                return;
                        }
                        r=(*p)(a,b);
			printf("r=%d\n",r);
			break;
		default:
			printf("wrong option\n");

	}
	dlclose(handler);
}

