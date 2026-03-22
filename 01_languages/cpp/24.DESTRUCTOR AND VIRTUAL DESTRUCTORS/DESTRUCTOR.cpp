#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class demo
{
public:
    demo()
    {

        cout << "constructor of the  demo class" << endl;
    }
    ~demo()
    {
        cout << "the object is destroyed" << endl;
    }
};
void func()
{
    demo *p = new demo();
    delete p; // object is destroyed by calling this
}
int main()
{

    func();

    return 0;
}