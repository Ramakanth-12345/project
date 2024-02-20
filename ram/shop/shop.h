#include<iostream>
#include<fstream>
using namespace std;
map<string,double>m;
double bill=0;
class shop
{
	//map<string,double> m;
	protected:
		char item_name[30];
		int item_number;
		double item_price;
	public:
		int total_items=100;
		double shop_cart(map<string,double>);
		void write_product(string);
		void create_product();
		int Adding_items();
		int shopping_menu();
		map<string,double> Search_product(string);
		void display_product(string);
}s;
