#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class shape
{
public:
    virtual int display() = 0;
};
class rectangle : public shape
{
    int display()
    {
        cout << "the shape is rectangle " << endl;
    }
};
class circle : public shape
{
    int display()
    {
        cout << "the shape is circle " << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    shape *ptr = new rectangle();
    ptr->display();
    ptr = new circle();
    ptr->display();
    return 0;
}