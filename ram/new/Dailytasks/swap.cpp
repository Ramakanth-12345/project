//program to implement Swap function using function overloading for character datatype,interger and double datatypes.

#include<iostream>
using namespace std;
class swapping
{
	public:
	int a,b;
	float c,d;
	char x,y;
	swapping()
	{
		cout<<"enter the a and b values\n"<<endl;
		cin>>a>>b;
		cout<<"enter the c and d values\n"<<endl;
		cin>>c>>d;
		cout<<"enter the x and y values\n"<<endl;
		cin>>x>>y;
	}
	void swapp(int a,int b)
	{
		int m;
		m=a;
		a=b;
		b=m;
	}
	void swapp(float c,float d)
	{
		float k;
		k=c;
		c=d;
		d=k;
	}
	void swapp(char x,char y)
	{
		char n;
		n=x;
		x=y;
		y=n;
	}
	void print()
	{
		cout<<"entered values are: "<<a<<" "<<b<<endl;
			cout<<"entered values are: "<<c<<" "<<d<<endl;
				cout<<"entered character are: "<<x<<" "<<y<<endl;
	}
	
};
int main()
{
	swapping k;
	k.swapp(k.a,k.b);
		k.swapp(k.c,k.d);
			k.swapp(k.x,k.y);
			k.print();
}
