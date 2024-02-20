//program to implement the Stack using template.Max stack size=10

#include<iostream>
using namespace std;
#define MAX 10
int top=-1;
template<class T>
class Stack
{
	public:
	T data;
	T arr[MAX];
	void push(T i)
	{
		if(top==MAX-1)
		cout<<"stack is full\n";
		else
		arr[++top]=i;
	}
	void pop()
	{
	cout<<arr[top--]<<endl;		
	}
	void peek()
	{
		cout<<arr[top]<<endl;
	}
};
int main()
{
	Stack<int>s1;
	Stack<char>s2;
	Stack<float>s3;
	int choice,val;
	cout<<"1.int 2.char 3.float"<<endl;
	cin>>val;
	if(val==1)
	{
	while(1)
	{
		cout<<"1.push 2.pop 3.peek 4.exit"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:	cout<<"enter the data"<<endl;
					cin>>s1.data;
					cout<<endl;
					s1.push(s1.data);
					break;
			case 2:	if(top==-1)
					cout<<"stack is empty"<<endl;
					else
					{
					cout<<"the data pop is:"<<endl;
					//cin>>data;
					s1.pop();
					}
					break;
			case 3:	if(top==-1)
					cout<<"stack is empty"<<endl;
					else
					{
					cout<<"the data pointed by top is:"<<endl;
					s1.peek();
					}
					break;
			case 4: return 1;
		}
	}
	}
	else if(val==2)
	{
	while(1)
	{
		cout<<"1.push 2.pop 3.peek 4.exit"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:	cout<<"enter the data"<<endl;
					cin>>s2.data;
					cout<<endl;
					s2.push(s2.data);
					break;
			case 2:	if(top==-1)
					cout<<"stack is empty"<<endl;
					else
					{
					cout<<"the data pop is:"<<endl;
					//cin>>data;
					s2.pop();
					}
					break;
			case 3:	if(top==-1)
					cout<<"stack is empty"<<endl;
					else
					{
					cout<<"the data pointed by top is:"<<endl;
					s2.peek();
					}
					break;
			case 4: return 1;
		}
	}
	}
	else if(val==3)
	{
	while(1)
	{
		cout<<"1.push 2.pop 3.peek 4.exit"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:	cout<<"enter the data"<<endl;
					cin>>s3.data;
					cout<<endl;
					s3.push(s3.data);
					break;
			case 2:	if(top==-1)
					cout<<"stack is empty"<<endl;
					else
					{
					cout<<"the data pop is:"<<endl;
					//cin>>data;
					s3.pop();
					}
					break;
			case 3:	if(top==-1)
					cout<<"stack is empty"<<endl;
					else
					{
					cout<<"the data pointed by top is:"<<endl;
					s3.peek();
					}
					break;
			case 4: return 1;
		}
	}
	}
	else
	cout<<"invalid"<<endl;	
}
