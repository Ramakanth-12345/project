#include<stdio.h>
#include<string.h>
int main()
{
char s[20];
int len,i;
gets(s);
for(i=0;s[i];i++)
{
	if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
	continue;
	else
	{
		memmove(s+i,s+i+1,strlen(s+i+1)+1);
		i--;
	}
}
printf("%s",s);
}
