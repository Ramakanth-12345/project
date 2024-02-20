#include<iostream>
#include<vector>
using namespace std;
int main()
{
vector<char> alphaVector;
 for( int i=0; i <=10; i++ ) {
 alphaVector.push_back( i+97  );
 }
 int size = alphaVector.size();
 vector<char>::iterator startIterator;
 vector<char>::iterator tempIterator;
 for( int i=0; i <size; i++ ) {
 startIterator = (alphaVector.end()-1);
 alphaVector.erase( startIterator );
 // Display the vector
 for( tempIterator = alphaVector.begin(); tempIterator !=
alphaVector.end(); tempIterator++ ) 
 {
 cout << *tempIterator;
 }
 cout << endl;
 } 
}
