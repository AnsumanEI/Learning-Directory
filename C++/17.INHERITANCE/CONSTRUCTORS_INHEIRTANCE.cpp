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
    inherit(int x, int a) : base(x)
    {
        cout << "inherit double parametre" << x << " " << a << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inherit obj(10, 20);

    return 0;
}