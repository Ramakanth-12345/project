#include <iostream>  
#include<vector>  
#include<iterator> 
using namespace std;
int main()
{
    vector<int>vec1 = {10, 20, 30, 40, 50, 60};
    vector<int>::iterator i1;
    vector<int>::iterator i2;
     i1 = vec1.begin();
     i2 = vec1.end();
    if ( i1 < i2)
    {
        cout << "Iterator i2 is greater than iterator i1.";
    }
   int difference = i2 - i1; 
    cout << "\nThe difference between i1 and i2 = " << difference;
    cout << "\n\n";
    return 0;
}
