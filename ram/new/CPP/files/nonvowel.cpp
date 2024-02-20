#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
	char fname[20],line[80];
	int cnt=0,i;
	cout<<"enter the file name"<<endl;
	cin>>fname;
	ifstream fin;
	fin.open(fname,ios::in);
	while(fin)
	{
		fin.getline(line,80);
		puts(line);
		for(i=0;line[i]!='\0';i++)
		{
			if(line[i]!='a'&&line[i]!='e'&&line[i]!='i'&&line[i]!='o'&&line[i]!='u'&&line[i]!='A'&&line[i]!='E'&&line[i]!='I'&&line[i]!='O'&&line[i]!='U')
				cnt++;
		}
	}
	cout<<"no.of non-vowels: "<<cnt<<endl;
	fin.close();
}
