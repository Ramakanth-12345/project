#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(9);
	v.push_back(10);
	cout<<"finding "<<binary_search(v.begin(),v.end(),3)<<endl;
	cout<<"lower bound "<<lower_bound(v.begin(),v.end(),9)-v.begin()<<endl;
	cout<<"upper bound "<<upper_bound(v.begin(),v.end(),3)-v.begin()<<endl;
}
