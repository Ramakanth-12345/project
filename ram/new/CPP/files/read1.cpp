#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	char myline[256];
	string ch;
	ofstream file("File.txt"); 
	file<<"enter the data"<<endl;
	file.close();
	ifstream read("");
	while(getline(read,ch));
	cout<<ch;
	file.close();
	ofstream append("File.txt",ios::app);
	append<<"this should append"<<endl;
	append.close();


}
