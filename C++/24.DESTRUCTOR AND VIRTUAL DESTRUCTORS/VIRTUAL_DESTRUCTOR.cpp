#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class base
{
public:
    // base()
    // {
    //     cout << " 1st base constructor " << endl;
    // }
    ~base()
    {
        cout << " 4th base destructor" << endl;
    }
};
class derived : public base
{
public:
    // derived()
    // {
    //     cout << " 2nd derived constructor" << endl;
    // }
    ~derived()
    {
        cout << " 3rd derived destructor" << endl;
    }
};

void func()
{
    base *ptr = new derived();
    delete ptr;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 1st derived destructor is called then base destructor which is vice a versa as of constructors
    // derived obj;
    //  now for base class pointer derived class object
    // base *ptr = new derived();
    //  if we declare object dynamically we also have to delete it so
    // delete ptr;
    // but if normal destructors are used only base class destructor will be called as the ptr the objects depends on the pointer
    // and the pointer is of base class only
    // so to call the derived destructor also we use virtual destructors
    func();

    return 0;
}