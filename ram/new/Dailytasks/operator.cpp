//Program to overload + operator (using member function)

#include<iostream>
using namespace std;
class ADD
{
	public:int a;
	ADD(int b=0)
	{
		//cout<<"enter the values"<<endl;
		a=b;
	}
	ADD &operator +(ADD &f)
	{
		static ADD Z;
		Z.a=a+f.a;
		return Z;
	}
	void print()
	{
		cout<<a<<" ";
	}	
	
};
int main()
{
	int a;
	cout<<"enter value\n"<<endl;
	cin>>a;
	ADD A(a);
	//A.print();
	cout<<"enter value"<<endl;
	cin>>a;
	ADD B(a);
	//B.print();
	ADD C;
	C=A+B;
	C.print();
	
		
}
