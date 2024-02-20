//using namespace std;
class A;
class B
{
	int b;
	public:
	B()
	{
		cout<<"enter the A value"<<endl;
		cin>>b;
	}
	friend void add(A& t,B& s);
}s;
void add(A &t,B &s)
{
	int c;
	c=t.a+s.b;
	cout<<"c= "<<c<<endl;
}
