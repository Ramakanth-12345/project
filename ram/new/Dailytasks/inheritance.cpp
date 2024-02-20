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
        	college::clgRead();
            cout<<"enter name"<<endl;
            cin>>NAME;
            cout<<"enter age"<<endl;
            cin>>age;
        }
        
        void perDisplay()
        {
            cout<<NAME<<endl;
            cout<<age<<endl;            
        }
};
class student:virtual public Person
{
    int rollno;
   // char studentname[MAX];
    public:
        void studentRead()
        {
        	college::clgDisplay();
            Person::perRead();
            cout<<"enter rollno."<<endl;
            cin>>rollno;
            //cout<<"studentname"<<endl;
            //cin>>studentname;    
        }
        void studentDisplay()
        {
            Person::perDisplay();
            cout<<rollno<<endl;
           // cout<<studentname<<endl;
        }     
};
class Staff:virtual public Person
{
    char staff[MAX];
    char workplace[MAX];
    public:
        void staffRead()
        {
            Person::perRead();
            cout<<"enter staff"<<endl;
            cin>>staff;
            cout<<"workplace"<<endl;
            cin>>workplace;    
        }
        void staffDisplay()
        {
            Person::perDisplay();
            cout<<staff<<endl;
            cout<<workplace<<endl;
        }        
};
class depart:public student,public Staff
{
    char Branch[MAX] ;
    char block[MAX];
    public:
        void depRead()
        {
            student::studentRead();
            Staff::staffRead();
            cout<<"enter Branch"<<endl;
            cin>>Branch;
            cout<<"enter block"<<endl;
            cin>>block;    
        }
        void depDisplay()
        {
            student::studentDisplay();
            Staff::staffDisplay();
            cout<<Branch<<endl;
            cout<<block<<endl;
        }
};
int main()
{
    //college col;
    depart dep;
    dep.depRead();
    dep.depDisplay();
}
