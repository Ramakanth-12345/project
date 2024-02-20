#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
queue<string> waiting_line;
 while( waiting_line.size() < 5 ) 
 {
 	cout << "Welcome to the line, please enter your name: ";
 	string s;
 	getline( cin, s );
 	waiting_line.push(s);
 }
 while(!waiting_line.empty() ) 
 {
 	cout << "Now serving: " << waiting_line.empty() << endl;
 	waiting_line.pop();
 }
}
