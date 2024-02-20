#include<iostream>
#include<map>
int main()
{
	map<int,int>m;
	m={{1,1},{2,2},{3,3},{4,4}};
	map<string,int>map1;
	map1["abc"]=100;
	map1["d"]=200;
	map1["cd"]=300;
	map<char,int>map2(map1.begin(),map1.end());
	for(map<int>)
	cout<<*m<<" "<<endl;
	cout<<*map1<<" "<<endl;
	cout<<*map2<<" "<<endl;
}
