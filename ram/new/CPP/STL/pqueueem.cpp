#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	for(int i=0;i<5;i++)
	{
		v.push_back(i+1);
	}
	while(v.empty())
	{
		cout<<v.top()<<endl;
		v.pop();
	}
} 
