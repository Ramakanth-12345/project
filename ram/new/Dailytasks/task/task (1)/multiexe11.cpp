#include<iostream>
using namespace std;
void check (int k) throw (int)
{
if (k==1) throw 'k';
else
if (k==2) throw k;
else
if (k==-2) throw 1.0;
}
int main()
{
try {
//check(1);
//check(-2);
check(2);
}
catch (char g)
{
cout<<"Caught a character exception \n";
}
catch (int j)
{
cout<<"Caught a integer exception \n";
}
catch (double s)
{
cout<<"Caught a double exception \n";
}
cout<<"\n End of main()";
return 0;
}
