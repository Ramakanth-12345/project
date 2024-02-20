#include<iostream>
#include<vector>
#include<iterator>
using namespace std;  
int main()  
{  
	//int a[]={1,2,3,4,5};
  vector<int> v{1,2,3,4,5}; 
	vector<int>::iterator it1,it2,temp; 
 it1 = v.begin();   // will point to the first element, i.e. 1
 it2 = v.end()-1;  // will point to the last element, i.e. 5
 cout << "Before Swapping" << endl;
 cout << "Dereferenced iterator 1: " << *it1 << " " ;
 cout << "\n";  
 cout << "Dereferenced iterator 2: " << *it2;
 cout << "\n\n";
	 temp = it1;  
   	 it1 = it2;  
     it2 = temp;   
 cout << "Before Swapping" << endl;
 cout << "Dereferenced iterator 1: " << *it1 << " " ;
 cout << "\n";  
 cout << "Dereferenced iterator 2: " << *it2;
 cout << "\n\n";
	return 0;  
}  
