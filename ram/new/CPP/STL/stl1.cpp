#include<vector>
#include<iostream>
//#include<Tracer>
using namespace std;
int main()
{
int a, b, c;
vector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(4);
cout << "Iterating:" << endl;
// "auto" is a C++11 feature not available on older compilers
for (vector<int>::iterator i=vec.begin();i!=vec.end();i++) 
{
cout << *i << "  ";
}
cout << "Done iterating!" << endl;
return 0;
}
