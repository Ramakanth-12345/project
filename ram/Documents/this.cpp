#include<iostream>
using namespace std;
class A
{
    private:
    int x;
    int y;
    int z;

    public:
    void set(int x,int y,int z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }
    void display()
    {
        cout<<"x :"<<x<<endl;
        cout<<"y:"<<y<<endl;
        cout<<"z:"<<z<<endl;
    }
};
int main()
{
    A obj;
    obj.set(20,30,40);
    obj.display();
    return 0;
}