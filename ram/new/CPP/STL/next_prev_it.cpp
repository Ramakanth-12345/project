#include<iostream> 
#include<iterator>
#include<vector>
using namespace std; 
int main() 
{ 
    vector<int> myVect = { 100, 200, 300, 400, 500 };
	vector<int>::iterator i1 = myVect.begin(); 
    vector<int>::iterator i2 = myVect.end(); 
    auto nextptr = next(i1, 3); 
    auto prevptr = prev(i2, 3); 
    cout << "The new pointer after using next() now points to : "; 
    cout << "\n";
    cout << *nextptr << " "; 
    cout << "\n\n"; 
    cout << "The new pointer after using prev() now points to : "; 
    cout << "\n";
    cout << *prevptr << " "; 
    cout << "\n\n"; 
    return 0;  
}
