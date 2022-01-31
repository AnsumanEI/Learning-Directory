#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
// friend class use to access private and protected members of a class or function outside the class or function
class base2;
int randomfunction();
class base
{
private:
    int a;
    int b;

public:
    int hello()
    {
        cout << "hello ";
        cout << a + b << endl;
    }
    friend base2;
    friend int randomfunction();
};

class base2
{
    // now this can access all the functions and variable of base class
public:
    int call()
    {
        base b;
        b.a = 10;
        b.b = 20;
    }
};

int randomfunction()
{
    base b1;
    b1.a = 20; // this can be called as random function is now a friend
    b1.b = 30;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}