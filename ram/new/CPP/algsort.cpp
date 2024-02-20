#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
	//function<bool(int&)> cond=[](int &a){return a<10;};
	vector<int>v;
	int n,j;
	cin>>n;
	for(int i=0;i<n;i++)
	{
			cin>>j;
			v.push_back(j);
	}
	//sort(v.begin(),v.end());
//	int b;
//	cin>>b;
	//auto it=adjacent_find(v.begin(),v.end(),2);
//	cout<<count_if(v.begin(),v.end(),[&](const int &a){
//			return a<b;});
//	cout<<endl;
//	cout<<*(it);
	//for(int x:v)
		//cout<<x<<" ";
		
	/* for perform square*/
//	for_each(v.begin(),v.end(),[](int &a){
//		cout<<a*a<<endl;	});
//		/*for random shuffle*/
		random_shuffle(v.begin(),v.end());
		for(int x:v)
			cout<<x<<" ";
}
