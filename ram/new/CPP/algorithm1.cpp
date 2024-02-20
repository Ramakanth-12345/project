#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	vector<int> a={1,2,3,4,5};
	vector<int> b={1,2,3,7,3};
	//vector<string>a{"ram","raghu"};
	//vector<string>b{"shyam","kiran"};
	vector<int> c(10);
	/*pair<vector<int>::iterator,vector<int>::iterator>p;
	auto p=mismatch(a.begin(),a.end(),b.begin(),b.end(),[](int a,int b){
		return a>=b;});
//	for(auto it:p)
	cout<<*(p.first)<<","<<*(p.second)<<endl;*/
	/* for union prining*/
	set_union(a.begin(),a.end(),b.begin(),b.end(),c.begin());
	for(int x:c) cout<<"set_union: "<<x<<" ";
	cout<<endl;
//set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
     set_difference(a.begin(),a.end(),b.begin(),b.end(),c.begin());
	for(int x:c) cout<<"set_difference: "<<x<<" ";
	cout<<endl;

     set_symmetric_difference(a.begin(),a.end(),b.begin(),b.end(),c.begin());
	for(int x:c) cout<<"set_symmetric: "<<x<<" ";
	cout<<endl;

     set_intersection(a.begin(),a.end(),b.begin(),b.end(),c.begin());
	for(int x:c) cout<<"merge: "<<x<<" ";
	return 0;
}
