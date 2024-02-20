//simple program for vector assign
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v{1,2,3,4};
	//vector<int>v;
	v.push_back(10);
	v.push_back(20);
	for(vector<int>::iterator i=v.begin();i!=v.end();i++)
	{
		cout<<*i<<" ";
	}
	for(auto it:v)
	{
		cout<<it<<" ";
	}
	return 0;
}
