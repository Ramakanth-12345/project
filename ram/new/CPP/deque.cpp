#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> d;
	d.push_back(1);
	d.push_front(3);
	for(int i:d)
	{
		cout<<i<<" ";
	}
	//d.pop_front();
	//d.pop_back();
	cout<<endl;
	//for(int i:d)
	//{
	//	cout<<i<<" ";
	//}
	cout<<"empty: "<<d.empty()<<endl;
	cout<<"size: "<<d.size()<<endl;
	d.erase(d.begin());
	cout<<"After Erase: "<<d.size()<<endl;
}
