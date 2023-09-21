#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class complex
{
public:
    int real;
    int img;

public:
    complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    complex add(complex x)
    {
        complex temp;
        temp.real = real + x.real;
        temp.img = img + x.img;
        return temp;
    }
    // we can make it an operator by typing operator+  instead off that add or whatever the name is
    complex operator+(complex x)
    {
        complex temp;
        temp.real = real + x.real;
        temp.img = img + x.img;
        return temp;
    }
    friend ostream &operator<<(ostream &o, complex &y);
};
ostream &operator<<(ostream &o, complex &y)
{
    o << y.real << " + i" << y.img;
    return o;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // overloaded functions addition
    complex c1(10, 6);
    complex c2(5, 6);
    complex c3;
    complex c4(10, 10);
    c3 = c1.add(c2);
    cout << c3.real << " + i" << c3.img << endl;
    // or
    c3 = c1 + c4;
    cout << c3;

    return 0;
}