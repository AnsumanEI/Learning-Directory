#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class rational
{
public:
    int num;
    int den;

public:
    rational(int num = 0, int den = 1)
    {
        this->num = num;
        this->den = den;
    }
    friend rational operator+(rational n, rational d);
    friend ostream &operator<<(ostream &o, rational &c);
};
rational operator+(rational a, rational b)
{
    rational temp;
    temp.num = a.num * b.den + b.num * a.den;
    temp.den = a.den * b.den;
    return temp;
}
ostream &operator<<(ostream &o, rational &c)
{
    o << c.num << "/" << c.den;
    return o;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    int x1, y1;
    x = 1;
    y = 2;
    x1 = 1;
    y1 = 2;
    rational c1(x, y);
    rational c2(x1, y1);
    rational c3;
    c3 = c1 + c2;

    cout << "sum of " << c1 << " and " << c2 << " is " << c3 << endl;
    return 0;
}