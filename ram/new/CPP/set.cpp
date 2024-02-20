#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int>s;
	s.insert(5);
	s.insert(1);
	s.insert(5);
	s.insert(3);
	s.insert(8);
	s.insert(2);
	s.insert(4);
	s.insert(0);
	for(auto i:s)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	set<int>::iterator it=s.begin();it++;
	s.erase(it);
	for(auto i:s)
	{
		cout<<i<<endl;
	}
	cout<<endl;
	set<int>::iterator itr=s.find(5);
	for(auto it=itr;it!=s.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"print 3: "<<s.count(3)<<endl;



}
