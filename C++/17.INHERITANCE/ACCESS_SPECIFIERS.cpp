#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
// access specifiers means
// eg private public protected
// these three are the access specifiers in the class
// protected means it can only be accessed in other class which is derived from the base class and is not accessible by objects also
// private cannot be accessed any where instead of the class itself
// public can be accessed any where
class base
{
private:
    int a;

protected:
    int b;

public:
    int c;
    int funcbase()
    {
        int a = 0;
        int b = 1000;
        int c = 2000;
    }
};
class derived : public base
{
private:
    int alpha;

public:
    int beta;
    int funderived()
    {

        // a=10;//private is only accesible in the same class
        b = 20; // protected can be accessed without a pointer
        c = 30; ////public is accesible always
        // accessibility using pointers can be only done in the same class,or is used for calling inside main functions
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    base b;
    // b.a=101;//private note accessible
    // b.b=102;//protected also not accessible
    b.c = 103; // public is accessed
    cout << b.c << endl;
    derived d;
    // d.a=11;
    // d.b=12;//protected can be accessed in the derived class but not through objects ,only through functions
    d.c = 13;
    cout << d.c << " " << b.c << endl;
    d.funderived();
    cout << d.c << endl;
    b.c = 111;
    b.funcbase();
    cout << b.c << endl;

    return 0;
}