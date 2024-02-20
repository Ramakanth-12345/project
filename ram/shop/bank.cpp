//fstream i; 
void Bank::Acc_details()
{
//	fstream f;
	f.open("bank.txt",ios::out|ios::app);
//	f.write((char*)&b,sizeof(bank));
	cout<<"Enter acc_no and name"<<endl;
	cin>>acc_no>>name;
	cout<<"type of account"<<endl;
	cin>>type;
	cout<<"Enter the how much to be money to deposited"<<endl;
	cin>>money_deposit;
	f.write((char*)&b,sizeof(Bank));
	f.close();
}
void Bank::Display()
{
	fstream fobj;
	fobj.open("bank.txt",ios::in);
//	while(!f.eof())
	fobj.seekg(0);
	while(fobj.read((char*)&b,sizeof(b)))
	{	
		cout<<"Acc_no   : "<<b.acc_no<<endl;
		cout<<"Name     : "<<b.name<<endl;
		cout<<"Acc_Type : "<<b.type<<endl;
		cout<<"Money    : "<<b.money_deposit<<endl;
//	f.read((char*)&b,sizeof(Bank));
	}
	fobj.close();
}
void Bank::Withdrawal(double &money_deposit)
{
	int amount,acc;
	cout<<"enter the account from which you want to withdraw"<<endl;
	cin>>acc;
	f.open("bank.txt",ios::out|ios::in|ios::binary);
	cout<<"Enter the Amount to withdraw:"<<endl;
	cin>>amount;
	while(f.read((char*)&b,sizeof(Bank)))
	{
		if(acc==acc_no)
		{
			if((amount<=money_deposit)&&(money_deposit>=500))
			{
				money_deposit-=amount;
				cout<<"Balance after withdrawal is: "<<money_deposit<<endl;
				f.write((char*)&b,sizeof(Bank));
			}
			else
			{
				cout<<"you don't have minimum balance"<<endl;
				return;
			}
			f.close();
			return;
		}
		else
			cout<<"Acc number is not matching"<<endl;

	}
	f.close();
}
void Bank::balance_enquiry(double &money_deposit)
{
	cout<<"The Amount in the acc is: "<<money_deposit<<endl;
}
void Bank::deposit(double &money_deposit)
{       
	int amount,acc;
        cout<<"enter the acc you want to deposit"<<endl;
        cin>>acc;
        f.open("bank.txt",ios::out|ios::in|ios::binary);
        cout<<"Enter the Amount to deposit:"<<endl;
        cin>>amount;
        while(f.read((char*)&b,sizeof(Bank)))
        {
                if(acc==acc_no)
                {
                       // if((amount<=money_deposit)&&(money_deposit>=500))
                        //{
                                money_deposit+=amount;
                                cout<<"Balance after withdrawal is: "<<money_deposit<<endl;
                                f.write((char*)&b,sizeof(Bank));
                        //}
                        f.close();
                        return;
                }
                else
                        cout<<"Acc number is not matching"<<endl;
        }
	f.close();	
}
void Bank::Menu()
{
	int ch;
	char i;
	do{
	cout<<"Enter the options to access"<<endl;
	cout<<"1.Acc_details\t2.Display\t3.Withdrawal\t4.Enquiry\t5.deposit\t6.Exit\n";
	cin>>ch;
		switch(ch)
		{
			case 1:Acc_details();
			       break;
			case 2:Display();
			       break;
			case 3:Withdrawal(money_deposit);
			       break;
			case 4:balance_enquiry(money_deposit);
			       break;
			case 5:deposit(money_deposit);
			       break;
			case 6:exit(0);
			default:cout<<"\nenter the correct option"<<endl;
		}
		cout<<"do you want to continue:y/n"<<endl;
		cin>>i;
	}while(i=='y'||i=='Y');
	return ;
}
void Transaction(Bank &b)
{
	int code=112233,pass,amount;
	char i;
	do{
		cout<<"Enter the password"<<endl;
		cin>>pass;
		if(pass==code)
		{
			cout<<"enter the amount to be transferred"<<endl;
			cin>>amount;
			if(b.money_deposit<=500)
			{
				cout<<"less than  min amount : "<<b.money_deposit<<endl;
			}
			else
			{
				b.money_deposit-=amount;
			}
		}
		else 
			cout<<"enter correct password"<<endl;
		cout<<"do you want transfer again Y/N"<<endl;
		cin>>i;
	}while(i=='Y' || i=='y');
}
