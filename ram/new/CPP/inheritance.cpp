#include<iostream>
using namespace std;
#define MAX 30
class college
{
	private:
		char clgname[MAX];
		char clglocation[MAX];
	public:
		void clgRead()
		{
			cout<<"enter college name"<<endl;
			cin>>clgname;
			cout<<"enter clg location"<<endl;
			cin>>clglocation;
		}
		void clgDisplay()
		{
			cout<<clgname<<endl;
			cout<<clglocation<<endl;			
		}
};
class Person:public college
{
	char NAME[MAX];
	int age;
	public:
		void perRead()
		{
			cout<<"enter name"<<endl;
			cin>>name;
			cout<<"enter age"<<endl;
			cin>>age;
		}
		void perDisplay()
		{
			cout<<name<<endl;
			cout<<age<<endl;			
		}
};
class depart:public college
{
	int Number;
	char block[MAX];
	public:
		void depRead()
		{
			college::clgRead();
			cout<<"enter number"<<endl;
			cin>>Number;
			cout<<"enter block"<<endl;
			cin>>block;	
		}
		void depDisplay()
		{
			college::clgDisplay();
			cout<<Number<<endl;
			cout<<block<<endl;
		}
};
class Branch:public depart
{
	char branchname[MAX];
	int studno;
	public:
		void branRead()
		{
			depart::depRead();
			cout<<"enter branchname"<<endl;
			cin>>branchname;
			cout<<"enter studno"<<endl;
			cin>>studno;	
		}
		void branDisplay()
		{
			depart::depDisplay();
			cout<<branchname<<endl;
			cout<<studno<<endl;
		}
	
};
class Staff:virtual public college
{
	char staff[MAX];
	char workplace[MAX];
	public:
		void staffRead()
		{
			college::clgRead();
			cout<<"enter staff"<<endl;
			cin>>staff;
			cout<<"workplace"<<endl;
			cin>>workplace;	
		}
		void stafDisplay()
		{
			college::clgDisplay();
			cout<<staff<<endl;
			cout<<workplace<<endl;
		}		
};

int main()
{
	//college col;
	Branch dep;
	dep.branRead();
	dep.branDisplay();
	
	
}
