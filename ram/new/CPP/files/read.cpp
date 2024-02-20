#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream myfile;
	myfile.open("example.txt");
	myfile<<"writing this to a file\n";
	myfile.close();
}
