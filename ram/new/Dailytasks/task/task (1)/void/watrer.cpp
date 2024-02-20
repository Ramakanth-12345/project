#include<iostream>
using namespace std;
class Water_Bottle
{
	
	public:
		string name;
		virtual void type()
		{
			cout<<"enter cc the type"<<endl;
			cin>>name;
		} 
		virtual void print()
		{
			cout<<"typecc of bottle is: "<<name<<endl;
		}
};
class Type :public Water_Bottle
{
	//string name;
	public:
		void type()
		{
			cout<<"enter the type"<<endl;
			cin>>name;
		}
		void print()
		{
			cout<<"type of bottle is: "<<name<<endl;
		}
};
int main()
{
	Water_Bottle *ptr=new Type;
	ptr->type();
	ptr->print();
}
