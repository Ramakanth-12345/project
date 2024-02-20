#include<bits/stdc++.h>
using namespace std;  
template<class FIterator>                               
void forwardIterator(FIterator start, FIterator end)   
{  
    while(start != end)  
     {  
        cout << *start << " ";  
        start++;  
	 }
}  
int main()
{ 
  vector<int> v1;  
  for(int i = 1; i <= 10; i++)  
  {
      v1.push_back(i + 2);  
  }  
 forwardIterator(v1.begin(),v1.end());  
  cout<<"\n";
  return 0;  
}
