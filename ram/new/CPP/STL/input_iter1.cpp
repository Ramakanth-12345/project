#include <iostream>  
#include<vector>  
#include<iterator>  
using namespace std;  
int main()  
{  
    vector<int> v={11,22,33,44};  
    vector<int>::iterator it,it1,temp;  
    it = v.begin();  
    it1 = v.begin()+1;  
    temp=it;  
    it=it1;  
    it1=temp;  
    cout<<*it<<" ";  
    cout<<*it1;  
    return 0;  
}  
