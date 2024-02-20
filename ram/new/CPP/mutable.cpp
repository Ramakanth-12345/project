#include<iostream>
using namespace std;
class A
{
	public:
	int x;
	mutable int y;
	A()
	{
		cout<<"enter the values"<<endl;
		cin>>x>>y;
	}
	void pre()
	{
		++x;
		++y;
	}
	void Display() const
	{
		
		cout<<"x:"<<x<<endl;
		cout<<"y:"<<++y<<endl;
	}
	
  
};

int main()
{
	A a;
	a.pre();
	a.Display();
}
