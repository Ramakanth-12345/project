#include<iostream>
#include<list>
using namespace std;
int main()
{
	int a[]={1,5,8,9,6,3,0,4};
	list<int>l(a,a+8);
	l.push_front(6);
	l.reverse();
	l.size();
	for(list<int>::iterator i=l.begin();i!=l.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<"\n"<<l.size()<<" ";
}
