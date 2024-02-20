#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<int,int>m;
	int max=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		m[x]++;
		for(auto it= m.begin(); it != m.end(); it++)
		{
			cout<<"Key :: "<<it->first<<"\t"<<"Value :: "<<it->second<<"\n";

		}
		if(m[x]>m[max])
			max=x;
	}
	cout<<max<<endl;

}
