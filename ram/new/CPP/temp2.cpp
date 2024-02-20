#include<iostream>
using namespace std;
template<class T>
class X
{
	template<class U>
	class Y
	{
		U *u;
		public:
			Y();
			U& value();
			void print();
			~Y();
	};
	Y<int>y;
	public:
		X(T t)
		{
			y.value()=t;
		}
		void print()
		{
			y.print();
		}
};
template<class T>
template<class U>
X<T>::Y<U>::Y()
{
	cout<<"X<T>::Y<U>::Y()"<<endl;
	u=new U();
	cout<<endl;
}
template<class T>
template<class U>
U& X<T>::Y<U>::value()
{
	return *u;
}
template<class T>
template<class U>
void X<T>::Y<U>::print()
{
	cout<<this->value()<<endl;
}
template<class T>
template<class U>
X<T>::Y<U>::~Y()
{
	cout<<"X<T>::Y<U>::~Y()"<<endl;
	delete u;
	cout<<endl;
}
int main()
{
	X<int>*xi=new X<int>(10);
	X<char>*xc=new X<char>('a');
	X<float>*xf=new X<float>(21.2f);
	xi->print();
	xc->print();
	xf->print();
	delete xi;
	delete xc;
	delete xf;
}

