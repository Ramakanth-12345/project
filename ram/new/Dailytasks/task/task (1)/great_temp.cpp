#include<iostream>
using namespace std;
template<class T>
class myclass
{
	T a,b,c;
	public:
	myclass(T first,T second,T three)
	{
		a=first;
		b=second;
		c=three;
	}
	T getmax();
};
template<class T>
T myclass<T>::getmax()
{
	return (a>b?(a>c?a:c):(b>c?b:c));
};
int main()
{
	myclass<int>my(10,30,40);
	myclass<char>mych('A','Z','G');
	cout<<"greater 10 or 30: "<<my.getmax()<<endl;
	cout<<"greater A or Z: "<<mych.getmax()<<endl;
}


