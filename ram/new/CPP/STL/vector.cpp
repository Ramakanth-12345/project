#include<vector>
#include<iostream>
#include "Tracer.h"
using namespace std;
int main(int argc,int *argv[])
{
Tracer a, b, c;
vector<Tracer> vec;
vec.push_back(a);
vec.push_back(b);
vec.push_back(c);
cout << "Iterating:" << endl;
// "auto" is a C++11 feature not available on older compilers
for (vector<int>::iterator i=vec.begin();i!=vec.end();i++) 
{
cout << *i << "  ";
}
cout << "Done iterating!" << endl;
return 0;
}
