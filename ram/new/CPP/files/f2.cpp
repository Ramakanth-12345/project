#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream inf("sample.dat");
	if(!inf)
	{
		cerr<<"Uh oh,sample.dat could not open for reading"<<endl;
		exit(1);
	}
	while(inf)
	{
		std::string strInput;
		//inf>>strInput;
		getline(inf,strInput);
		cout<<strInput<<endl;
	}
}

