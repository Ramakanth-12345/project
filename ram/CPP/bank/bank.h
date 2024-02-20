#include<bits/stdc++.h>
using namespace std;
class shop;
class bank
{
	int acc_no;
	char name[30];
	//protected:
	double money;
	public:
		void Acc_details();
		void Bank_menu();
		void Display();
		void withdraw(double&); 
		void Deposit(double&);
		friend void Transaction(bank&,shop&);
}b;
