#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char data[100];
	ofstream outfile;
	outfile.open("file.dat");
	cout<<"file to the file"<<endl;
	cout<<"enter the name"<<endl;
	cin.getline(data,100);
	outfile<<data<<endl;
	cout<<"enter your age: ";
	cin>>data;
	cin.ignore();
	outfile<<data<<endl;
	outfile.close();
	ifstream infile;
	infile.open("file.dat");
	cout<<"Reading from the file"<<endl;
	infile>>data;
	cout<<data<<endl;
	infile>>data;
	cout<<data<<endl;
	infile.close();
}
