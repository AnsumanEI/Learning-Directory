#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class base
{
public:
    virtual void display()
    {
        cout << "base class display" << endl;
    }
};
class derived : public base
{
public:
    void display()
    {
        cout << "derived class display" << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // virtual functions ignore a function if we are calling a function using pointer with diffrent class
    base *ptr = new derived();
    ptr->display(); // by default base class display will come
    // but if we make the display of the base class virtual the derived class function will be called

    return 0;
}