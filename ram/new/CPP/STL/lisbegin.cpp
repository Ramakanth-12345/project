#include<iostream>
#include<vector>
#include<cstdlib>
#include<list>
#include<map>
using namespace std;
int main()
{
 list<char>charList;
for( int i=0; i <=10; i++ ) 
{
charList.push_back( i + 65 );
}
// Display the list
list<char>::iterator theIterator;
for( theIterator = charList.begin(); theIterator != charList.end();
theIterator++ ) 
{
	cout << *theIterator;
} 
charList.remove(70);
//charList.insert(charList.begin(2),65,74);
cout<<"\n";
cout<<"size: "<<charList.size();
cout<<"\n";
for( theIterator = charList.begin(); theIterator != charList.end();
theIterator++ ) 
{
	cout << *theIterator;
} 
cout<<"\n";
//cout<<"size:"<<charList.size();
}
