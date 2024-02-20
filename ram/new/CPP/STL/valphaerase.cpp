#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main()
{
//	reverse_iterator rbegin();
	//reverse_iterator rend();
	deque<char> v;
	for(int i=0;i<10;i++)
	{
		v.push_front(i+65);
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i];
	}
	cout<<endl;
	v.erase(v.begin()+2,v.end()-1);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i];
	}
	
}
