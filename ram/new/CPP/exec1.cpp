#include<iostream>
using namespace std;
void sqr()
{
	int s;
	cout<<"\n Enter a number:";
	cin>>s;
	if (s>0)
	{
		cout<<"Square="<<s*s;
	}
	else
	{
		throw (s);
	}
}
int main()
{
	try
	{
		sqr();
	}
	catch (int j)
	{
		cout<<"\n Caught the exception \n";
	}	
return 0;
}
