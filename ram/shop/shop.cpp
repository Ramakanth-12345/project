void shop::create_product()
{
	cout<<"enter the item name"<<endl;
	cin>>s.item_name;
	//cout<<"Enter the item quantity"<<endl;
	//cin>>s.item_number;
	cout<<"enter the item price"<<endl;
	cin>>s.item_price;
}
void shop::write_product(string filename)
{
	int n;
	fstream of;
	cout<<"enter no of products"<<endl;
	cin>>n;
	of.open(filename,ios::out|ios::app);
	while(n)
	{
		s.create_product();
		of.write((char*)&s,sizeof(shop));
		n--;
	}
	of.close();
}
void shop::display_product(string filename1)
{
	fstream ip,op;
	cout<<"The prepared items are:"<<endl;
	cout<<"\tItem Name\tItemprice\n"<<endl;
	ip.open(filename1,ios::in);
	op.open("temp.txt",ios::out|ios::app);
	while(ip.read((char*)&s,sizeof(shop)))
	{
		cout<<"\t"<<s.item_name<<"\t\t";
		//cout<<"item_number: "<<s.item_number<<endl;
		cout<<s.item_price<<endl;
		//if(s.item_name && s.item_price !
		op.write((char*)&s,sizeof(shop));
		cout<<"\n";
	}
	op.close();
	ip.close();
}
int shop::Adding_items()
{
	int i;
	char c;
	fstream add;
	cout<<"\t\tAdmin Menu\t\n";
	do{
       		cout<<"1.Electronic\t2.Clothing\t3.Exit"<<endl;
		cout<<"Enter the options want to create"<<endl;
		cin>>i;
		switch(i)
		{
			case 1:add.open("electronic.txt",ios::out|ios::binary|ios::in);
			       write_product("electronic.txt");
			     //  display_product("electronic.txt");
			       add.close();
			       break;
			case 2:add.open("cloth.txt",ios::out|ios::binary|ios::in);
			       write_product("cloth.txt");
			       //display_product("cloth.txt");
			       add.close();
			       break;
			default: return 0;
		}
		cout<<"do you want add more products,press(y/n)"<<endl;
		cin>>c;
	}while(c=='y'||c=='Y');
}
map<string,double>shop::Search_product(string filename)
{
	string name;
	fstream f;
	int k;
	f.open(filename,ios::in);
	//map<string,double>m;
	cout<<"enter the name want to search"<<endl;
	cin>>name;
	if(!f)
	{
		cout<<"Error opening file"<<endl;
		//return ;
	}
	if(f.read((char*)&s,sizeof(shop)))
	{
		while(!(f.eof()))
		{
			if(s.item_name==name)
			{
			//	cout<<s.item_name<<"\t"<<s.item_price<<endl;
				m.insert(pair<string,double>(item_name,item_price));
				cout<<s.item_name<<"\t"<<s.item_price<<endl;
				break;
			}
			f.read((char*)&s,sizeof(shop));
		}
	}
	f.close();
	return m;
}
double shop::shop_cart(map<string,double>m)
{
	double i=0;
	map<string,double>::iterator iter;
	for(iter=m.begin();iter!=m.end();++iter)
	{
		cout<<"item_name: "<<iter->first<<"\titem_price: "<<iter->second<<endl;
		i+=iter->second;
	}
	cout<<"The Amount of the products is: "<<i<<endl;
	return i;

}
int shop::shopping_menu()
{
	int choice;
	char c;
	//map<string,double>map;
	fstream shop;
	cout<<"\t\tShopping Menu\t\n";
	do{
		cout<<"  1.Electronics\t2.Clothing\t3.Search_product\t4.shop_cart"<<endl;
		cout<<"Enter the choice to buy the product\t\n";
		cin>>choice;
		switch(choice)
		{
			case 1:shop.open("electronic.txt",ios::in);
			       display_product("electronic.txt");
			       shop.close();
			       break;
			case 2:shop.open("cloth.txt",ios::in);
			       display_product("cloth.txt");
			       shop.close();
			       break;
			case 3:m=Search_product("temp.txt");
			       break;
			case 4:bill=shop_cart(m);
			       break;
			default: return 0;
		}
		cout<<"do you want add more products,press(y/n)"<<endl;
		cin>>c;
	}while(c=='y'||c=='Y');
	cout<<"bill  : "<<bill<<endl;
}
