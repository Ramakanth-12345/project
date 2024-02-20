#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
	char filename[20],ch;
	int chcnt=0,wdcnt=1;
	cout<<"enter the file name"<<endl;
	cin.getline(filename,20);
	ifstream infile(filename);
	if(!infile)
	{
		cout<<"cannot open"<<endl;
		exit(0);
	}
	while(infile.get(ch))
	{
		if(ch==' ')
			wdcnt++;
		else 
			chcnt++;
	}
	cout<<"no.of words: "<<wdcnt<<endl;
	cout<<"no.of chara: "<<chcnt<<endl;	
}
