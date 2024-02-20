//using namespace std;
class B;
class A
{
	int a;
	public:
	A()
	{
		cout<<"enter the A value"<<endl;
		cin>>a;
	}
	friend void add(A &t,B &s);
}t;
