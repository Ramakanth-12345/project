#include <iostream>  
#include<vector>  
#include<iterator> 
using namespace std;
int main ()
 {
  vector<int> myVect1, myVect2;
  for (int i = 1; i <= 5; i++)
   { 
      myVect1.push_back(i);
      myVect2.push_back(i + 4);
   }
     vector<int>::iterator itr = myVect1.begin(); 
      copy (myVect2.begin(), myVect2.end(), inserter(myVect1, itr));
  cout<<"Elements of vector myVect1 after copying elements of myVect2 are :"<< endl;
   for ( itr = myVect1.begin(); itr!= myVect1.end(); ++itr ) 
   {
      cout << " " << *itr;
   }
      cout << "\n\n";
}
