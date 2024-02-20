#include<iostream>
using namespace std;
void sqr()
{
	int s;
	cout<<"enter the num: "<<endl;
	cin>>s;
	if(s>0)
	{
		cout<<"square of num: "<<s*s<<endl;
	}
	else
	throw(s);	
}
int main()
{
	try
	{
		sqr();
	}
	catch(int j)
	{
		cout<<"The theif got caught"<<endl;
	}
}
