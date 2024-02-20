#include<iostream>
using namespace std;
template<class T>
class vector
{
	T *v,*c;
	int size;
	public:
		vector(int vector_size)
		{
			size=vector_size;
			c=new T[size];
		}
		/*~vector()
		{
			delete v;
		}*/
		T &elem(int i)
		{
			if(i>size)
			cout<<"Error out of range"<<endl;
			return v[i];
		}	
		T show();
};
template<class T>
T vector<T>::show()
{
	for(int i=0;i<size;i++)
	cout<<elem(i)<<" ";
}
int main()
{
	int i;
	vector<int>int_vector(5);
	vector<float>float_vector(4);
	for(i=0;i<5;i++)
	{
		int_vector.elem(i)=i+1;
	}
	for(i=0;i<4;i++)
	{
		float_vector.elem(i)=i+1.5;
	}
	cout<<"Int vec"<<endl;
	int_vector.show();
	cout<<"float vec"<<endl;
	float_vector.show();
	
}
