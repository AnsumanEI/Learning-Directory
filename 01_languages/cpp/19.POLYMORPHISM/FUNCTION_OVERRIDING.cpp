#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class base
{
public:
    void display()
    {
        cout << "function of base class" << endl;
    }
};
class derived : public base
{
public:
    void display()
    {
        cout << "function of derived class" << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    base b;
    b.display();
    derived d;
    d.display();
    // function override occurs when same function is called from both the base and derived class but the function can be modified with respect to the object

    return 0;
}