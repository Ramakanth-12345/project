//#include"shop.h"
void bank::Acc_details()
{
	fstream f;
	f.open("bank.txt",ios::out);
	cout<<"Enter the Accno"<<endl;
	cin>>b.acc_no;
	cout<<"Enter of Acc holder"<<endl;
	cin>>b.name;
	cout<<"Enter the money want to deposit"<<endl;
        cin>>b.money;
	f.write((char*)&b,sizeof(bank));
f.close();	
}
void bank::Display()
{
	fstream f;
	f.open("bank.txt",ios::in);
	f.seekg(ios::beg);
	while(!f.eof())
//	{
	//ile(f<<b.acc_no<<b.name<<b.money)
	//while(f.read((char*)&b,sizeof(b)))
	{
		cout<<"Acc_no is : "<<b.acc_no<<endl;
		cout<<"Name is   : "<<b.name<<endl;
		cout<<"Money is  : "<<b.money<<endl;
//	return;
	f.read((char*)&b,sizeof(b));
	}
	f.close();
}
void bank::withdraw(double &money)
{
	fstream f;
	int acc,amount,code,pass=123;
	cout<<"Enter the acc no"<<endl;
	cin>>acc;
	cout<<"Enter the password"<<endl;
	cin>>code;
	if((pass==code)&&(b.acc_no==acc))
	{
		f.open("bank.txt",ios::in|ios::out);
		while(!f.eof())
		{
		cout<<"Enter the amount to withdraw"<<endl;
		cin>>amount;
		if((b.money>amount)&&(b.money>500))
		{
			b.money-=amount;
			//Display();
			f.write((char*)&b,sizeof(b));
			f.close();
			return ;
		}
		else
			cout<<"you have les amount"<<endl;
		}
		f.close();
	}
	else
		cout<<"you have entered wrong password or acc_no"<<endl;
	return ;
}
void bank::Deposit(double &money)
{ 
	fstream f;
	int acc,amount,code,pass=123;
        cout<<"Enter the acc no"<<endl;
        cin>>acc;
        cout<<"Enter the password"<<endl;
        cin>>code;
	if((pass==code)&&(b.acc_no==acc))
        {
		f.open("bank.txt",ios::in|ios::out);
	//	in.open("bank.txt");
		//while(f.read((char*)&b,sizeof(b)))
		while(!f.eof())
		{
                cout<<"Enter the amount to Deposit"<<endl;
                cin>>amount;
                if(amount>100)
                {
                        b.money+=amount;
			f.write((char*)&b,sizeof(b));
		//in<<b.money;
		f.close();
                        Display();
			//f.close();
			return ;
                }
                else
                        cout<<"you entered less amount"<<endl;
		}
		f.close();
        }
        else
                cout<<"you have entered wrong password or acc_no"<<endl;
                return ;
}
void bank::Bank_menu()
{
	int choice;
	char i;
	cout<<"-------------menu-------------"<<endl;
	do{
	cout<<"1.Display\t2.Withdraw\t3.Deposit\t4.acc_details\t5.return"<<endl;
	cin>>choice;
		switch(choice)
		{
			case 1:Display();
			       break;
			case 2:withdraw(money);
			       break;
			case 3:Deposit(money);
			       break;
			case 4:Acc_details();
			       break;
			case 5:return;
			default:cout<<"enter the correct option"<<endl;
		}
		cout<<"do you want continue Y/n"<<endl;
		cin>>i;
	}while(i=='y'||i=='Y');
	return ;
}
void Transaction(bank &b,shop &s)
{
	fstream f;
	int code=112233,pass,amount;
	char i;
	do{
		cout<<"Enter the password"<<endl;
		cin>>pass;
		if(pass==code)
		{
			f.open("bank.txt",ios::in);
			while(f.read((char*)&b,sizeof(b)))
			{
			cout<<"enter the amount to be transferred: "<<bill<<endl;
			//cin>>amount;
			if(b.money<=500)
			{
				cout<<"less than  min amount : "<<b.money<<endl;
			}
			else
			{
				b.money-=bill;
				cout<<"money is :"<<b.money<<endl;
				f.close();
			}
			}
			f.close();
		//}
			ifstream of("bank.txt");
			ofstream r("bank.txt");
			of.seekg(ios::beg);
			while(r<<b.acc_no<<b.name<<b.money)
			{
			of>>b.acc_no>>b.name>>b.money;
			cout<<"\n";
			cout<<"money saving : "<<b.money<<endl;
			break;
			}
			r.close();
			of.close();
			return;		
		}
		else
			cout<<"enter correct password"<<endl;
		cout<<"do you want transfer again Y/N"<<endl;
		cin>>i;
	}while(i=='Y' || i=='y');
}
