// program to create 1d integer array using new operator (Dynamically), initialize the array and print the array elements.

#include<iostream>
using namespace std;
class ARRAAY
{
	public:
		int *p=NULL;
		int size;
		int i;
		ARRAAY()
		{
			cout<<"enter the size"<<endl;
			cin>>size;
			p=new int[size];
			cout<<"enter the elements"<<endl;
			for(i=0;i<size;i++)
			{
				cin>>p[i];
			}	
		}
	//	~ARRAAY();
		void print(int *p,int size )
		{
			for(i=0;i<size;i++)
			{
				cout<<p[i]<<" ";
			}
		}
		~ARRAAY();
		*{
		delete p;
		*p=NULL;
		}f
};
int main()
{
	ARRAAY A;
	A.print(A.p,A.size);
}
