#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class base
{
public:
    base()
    {
        cout << "default constructor" << endl;
    }
    base(int a)
    {
        cout << "parameterised constructor" << a << endl;
    }
    ~base()
    {
        cout << "base is destroyed" << endl;
    }
};
class inherit : public base
{
public:
    inherit()
    {
        cout << "inherit default" << endl;
    }
    inherit(int x)
    {
        cout << "inherit parametre" << x << endl;
    }
    inherit(int x, int a)
    {
        cout << "inherit double parametre " << x << " " << a << endl;
    }
    ~inherit()
    {
        cout << "inheritance destroyed" << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inherit obj(10, 20);
    base b;

    return 0;
}