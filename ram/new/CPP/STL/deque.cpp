#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main()
{
	int a[]={1,5,8,9,6,3,0,4};
	deque<int>dq(a,a+8);
	dq.push_front(3);
	for(deque<int>::iterator i=dq.begin();i!=dq.end();i++)
	{
	cout<<*i<<" ";
	}
}
