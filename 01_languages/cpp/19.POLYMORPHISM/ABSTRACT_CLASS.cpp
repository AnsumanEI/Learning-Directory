#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
// abstract class means virtual functions will be assigned 0 , so that the class will be abstract
class base
{
public:
    int fun1()
    {
        cout << "fun 1 of base " << endl;
    }
    virtual int fun2() = 0; // as the fun2 is overriden in the derived class so fun 2 is made purely virtual and the class is now an abstract class
    // func2 cant be accessed from base class pointer and derived class object so  virtual function is made
};
class derived : public base
{
    int fun2()
    {
        cout << "fun 2 of derived class" << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    base *ptr = new derived();
    ptr->fun1();
    ptr->fun2();
    return 0;
}