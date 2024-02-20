#include<bits/stdc++.h>
#include<fstream>
#include"shop.h"
#include"bank.h"
#include"shop.cpp"
#include"bank.cpp"
//map<string,double> m;
fstream f; 
using namespace std;
int main()
{
	int choice;
	Bank b;b
	char c;
	cout<<"\t\t--------------Welcome to shopping portal----------"<<endl;
	do{
		cout<<"\t\t1.Adding_items\t\t2.shopping_menu\t\t3.Exit"<<endl;
		cout<<"Enter the choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:s.Adding_items();
			       break;
			case 2:s.shopping_menu();
			     	break;
			default: return 0;
		}
		cout<<"do you want to continue,press(y/n)"<<endl;
		cin>>c;	
	}while(c=='y'|c=='Y');	
}
