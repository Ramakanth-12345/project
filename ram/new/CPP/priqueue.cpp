#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int>max;
	//cout<<"after size "<<i.size()<<endl;
	priority_queue<int,vector<int>,greater<int>>min;
	max.push(30);
	max.push(20);
	max.push(10);
	cout<<"max size before pop "<<max.size()<<endl;
	for(int i=0;i<max.size();i++)
	{
	cout<<max.top()<<" ";
	//max.pop();
	}
	cout<<endl;
	cout<<"max size after pop "<<max.size()<<endl;
	min.push(31);
	min.push(21);
	min.push(11);
	cout<<"min size before pop "<<min.size()<<endl;
	for(int i=0;i<min.size();i++)
	{
	cout<<min.top()<<" ";
	//min.pop();
	}
	cout<<endl;
	cout<<"min size after pop "<<min.size()<<endl;
	cout<<"arey kaliga undha ledha: "<<max.empty()<<endl;
}
