#include<bits/stdc++.h>
using namespace std;
int main () 
{
   vector<int> v1, v2;
   for (int i = 1; i <= 10; i++)
   { 
    	v1.push_back(i);
		v2.push_back(i + 2);
   }
  vector<int>::iterator itr = v1.begin(); 
  copy (v2.begin(), v2.end(), inserter(v1, itr));
  cout<<"Elements of vector v1 after copying elements of v2 are :"<< endl;
   for (itr=v1.begin();itr!=v1.end();++itr) 
  	{
      cout << " " << *itr;
   	}
      cout << "\n";
}
