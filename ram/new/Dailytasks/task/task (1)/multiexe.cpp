#include<iostream>
using namespace std;
void num(int k)
{
	try
	{
		if(k==0)
			throw k;
		else
		if(k>0) throw 'P';
		else
		if(k<0) throw 1.0;
		cout<<"end of try block\n";
	}
	catch(char g)
	{
		cout<<"caught a positive\n";
	}
	catch(int j)
	{
		cout<<"caught a null value\n";
	}
	catch(double f)
	{
		cout<<"caught a negative value\n";
	}
	cout<<"**end of try block**\n";
}
int main()
{
	num(0);
//	num(9);
	num(5);
	num(-1);
	return 0;
}
