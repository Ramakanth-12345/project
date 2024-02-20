#include<iostream>
#include<fstream>
//fstream f;
using namespace std;
class Bank
{
	int acc_no;
	char name[30];
	char type[30];
	double money_deposit;
	public:
	fstream  f;
		void Acc_details();
		void Display();
		void balance_enquiry(double&);
		void Withdrawal(double&);
		void deposit(double&);
		void Menu();
		friend void Transaction(Bank &);
}b;


