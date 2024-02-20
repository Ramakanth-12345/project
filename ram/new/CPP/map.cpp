//#include<iostream>
//#include<map>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,string>m;
	m[1]="Ram";
	m[10]="sam";
	m[2]="raj";
	m[20]="sri";
	m[1]="king";

	m.insert({5,"kir"});
	for(auto i:m)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
	cout<<"finding 10 "<<m.count(10)<<endl;
	m.erase(10);
	cout<<"after Erase:"<<endl;
	for(auto i:m)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
	auto it=m.find(2);
	for(auto i=it;i!=m.end();i++)
	{
		cout<<(*i).first<<" "<<(*i).second<<endl;
	}
}
