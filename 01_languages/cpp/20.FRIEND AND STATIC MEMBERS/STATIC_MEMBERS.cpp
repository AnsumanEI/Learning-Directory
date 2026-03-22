#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class base
{
public:
    static int count; // static variable is allocated only once
    int fun()
    {

        count++;
    }
    static int getcount()
    {

        return count; // static functions can only access static variables
    }
};
int base::count = 0; // this means the static variable can only be used inside the base class
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    base b;
    b.fun();
    // or we can call it by scope resoluton operator if the function is static
    base::getcount();
    return 0;
}