//program to find LCM of two numbers using friend function
#include<iostream>
using namespace std;
class LCM
{
	public:
		int a,b;
		LCM()
		{
			cout<<"enter the values"<<endl;
			cin>>a>>b;
		}
		friend void LCM2(int,int);
};
void LCM2(int a,int b)
{
	int max;
	max=(a>b)?a:b;
	while(1)
	{
		if((max%a==0)&&(max%b==0))
		{
			cout<<max<<endl;
			break;
		}	
		++max;
	}	
}
int main()
{
	LCM A;
	LCM2(A.a,A.b);
}
