#include <iostream>  
#include<vector>  
#include<iterator>  
using namespace std;  
int main()  
{  
  vector<int> v1{10, 20, 30, 40, 50, 60}; 
  vector<int> ::iterator i1;  
  vector<int> :: reverse_iterator rItr;
  cout << "Values in original order: " << "\n";
   for(i1 = v1.begin(); i1 != v1.end(); i1++)  
   {  
       cout << *i1 << " ";  
   }  
   cout << "\n\n";  
   cout << "Values in reverse order: " << "\n";
   for(rItr = v1.rbegin(); rItr != v1.rend(); rItr++)  
   {  
       cout << *rItr << " ";  
   }  
   cout << "\n\n";
    return 0;  
}  
