#include<iostream>
using namespace std;
class X
{
	template<class T>
		struct Y
		{
			T m_t;
			Y(T t):m_t(t){}

		};
	Y<int>yint;
	Y<char>xchar;
	public:
	X(int i,char c):yint(i),xchar(c){}
	void print()
	{
		cout<<yint.m_t<<" "<<xchar.m_t<<endl;
	}
};
int main()
{
	X x(1,'a');
	x.print();
}
