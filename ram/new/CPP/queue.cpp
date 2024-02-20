#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<string>i;
	i.push("ram");
	i.push("sri");
	i.push("rajini");
	cout<<"before size "<<i.size()<<endl;
	cout<<"first element:  "<<i.front()<<endl;
	i.pop();
	cout<<"top -1: "<<i.front()<<endl;
	cout<<"after size "<<i.size()<<endl;
	i.pop();
	i.pop();
	cout<<"is empty "<<i.empty()<<endl;
	//cout<<"capacity "<<i.capacity()<<endl;
}
