#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	cout<<"without using vec fun"<<endl;
	for(int i=18;i>=1;i--)
	{
		v.push_back(i);
	}
	cout<<"using iterator"<<endl;
	for(auto i=v.begin();i!=v.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<"\n";
	v.pop_back();
	for(auto i=v.begin();i!=v.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
	cout<<"size of vector: "<<v.size()<<endl;
	cout<<"capacity of vector: "<<v.capacity()<<endl;
	v.resize(4);
	cout<<"size of vector after resize: "<<v.size();
	cout<<endl;
	cout<<"elememt at: "<<v.at(3)<<endl;
	return 0;
}
