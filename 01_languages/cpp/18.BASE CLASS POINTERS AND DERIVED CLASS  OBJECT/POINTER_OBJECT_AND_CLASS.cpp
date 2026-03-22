#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class rectangle
{
private:
    int length;
    int breadth;

public:
    rectangle(int length = 0, int breadth = 0)
    {
        this->length = length;
        this->breadth = breadth;
    }
    int area(int length, int breadth);
};
class cuboid : public rectangle
{
private:
    int height;

public:
    cuboid(int l = 0, int b = 0, int h = 0) : rectangle(l, b)
    {
        height = h;
    }
    int volume(int length, int breadth, int height);
};
int rectangle::area(int length, int breadth)
{
    return length * breadth;
}
int cuboid::volume(int length, int breadth, int height)
{
    return length * breadth * height;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cuboid obj;
    rectangle *ptr;
    ptr = &obj;

    rectangle *ptr1;
    ptr1 = new cuboid();
    // so this means that the parent class can access the the objects through pointer but the vice a versa is not true
    // ptr->volume10,10,10;//not possible as it can only handle the base functions means the object of the class of the function
    cout << ptr->area(10, 10) << endl;
    cuboid *c = new cuboid(); // possible as the object and pointer has the the same class cuboid
    cout << c->volume(10, 10, 20);
    return 0;
}