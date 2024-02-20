#include<stdio.h>
#include<dirent.h>
#include<sys/time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>
#include<grp.h>
#include<pwd.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,int *argv[])
{
	struct dirent *p;
	DIR *dp;
	int  i;
	struct stat v;
	char time[30];
	struct passwd *pw;
	struct group *gp;
	dp=opendir(".");
	stat(".",&v);
	if(dp==NULL)
	{
		printf("Directory problem in opening\n");
		return;
	}
	while((p=readdir(dp))!=NULL)
	{
		if(stat(p->d_name,&v)<0)
		{
			printf("stat failure\n");
			exit(0);
		}
		switch(v.st_mode&S_IFMT)
		{
			case S_IFREG:printf("-");
				     break;
			case S_IFDIR:printf("d");
				     break;
			case S_IFCHR:printf("c");
				     break;
			case S_IFBLK:printf("b");
				     break;
			case S_IFIFO:printf("p");
				      break;
			case S_IFSOCK:printf("s");
				      break;
			case S_IFLNK:printf("l");
				      break;
		}
		if(S_IRUSR&v.st_mode)
			printf("r");
		else
			printf("-");
		if(S_IWUSR&v.st_mode)
                        printf("w");
                else
                        printf("-");
		if(S_IXUSR&v.st_mode)
                        printf("x");
                else
                        printf("-");
		if(S_IRGRP&v.st_mode)
                        printf("r");
                else
                        printf("-");
		if(S_IWGRP&v.st_mode)
                        printf("w");
                else
                        printf("-");
		if(S_IXGRP&v.st_mode)
                        printf("x");
                else
                        printf("-");
		if(S_IROTH&v.st_mode)
                        printf("r");
                else
                        printf("-");
		if(S_IWOTH&v.st_mode)
                        printf("w");
                else
                        printf("-");
		if(S_IXOTH&v.st_mode)
                        printf("x");
                else
                        printf("-");

		printf("%3d",(int)v.st_nlink);
		pw=getpwuid(v.st_uid);
		printf("%s",pw->pw_name);
		gp=getgrgid(v.st_gid);
		printf("%s",gp->gr_name);
		printf("%5d",(int)v.st_size);
		strcpy(time,ctime(&v.st_mtime));
		for(i=0;time[i];i++);
		time[i-9]=time[i];
		printf("%-10s",time+4);
		printf("%-5s\n",p->d_name);
	}
}
