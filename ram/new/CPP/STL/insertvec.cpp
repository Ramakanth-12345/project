#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main()
{
vector<char> alphaVector;
for( int i=0; i < 10; i++ ) {
alphaVector.push_back( i + 65 );
}
// Insert four C's into the vector
vector<char>::iterator theIterator = alphaVector.begin();
alphaVector.insert( theIterator, 4, 'C' );
// Display the vector
for( theIterator = alphaVector.begin(); theIterator !=
alphaVector.end(); theIterator++ ) 
{
cout << *theIterator;
} 
}
