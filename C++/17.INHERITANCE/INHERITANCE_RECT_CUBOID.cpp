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
    rectangle(int length = 1, int breadth = 1)
    {
        this->length = length;
        this->breadth = breadth;
    }

    int setLength(int length);
    int getLength()
    {
        return length;
    };
    int setBreadth(int breadth);
    int getBreadth()
    {
        return breadth;
    };
    int area();
    int perimeter();
    bool isSquare();
    ~rectangle();
};
// inheritance class for cuboid
class cuboid : public rectangle
{
private:
    int height;

public:
    int volume();
    int getHeight()
    {
        return height;
    };
    int setHeight(int height);
};
// rectangle
int rectangle::setLength(int length)
{
    this->length = length;
}
int rectangle::setBreadth(int breadth)
{
    this->breadth = breadth;
}
int rectangle::area()
{
    return length * breadth;
}
int rectangle::perimeter()
{
    return 2 * length * breadth;
}
rectangle::~rectangle()
{
    cout << "the rectangle is destroyed" << endl;
}
bool rectangle::isSquare()
{
    return length == breadth;
}
// cuboid
int cuboid::setHeight(int height)
{
    this->height = height;
}
int cuboid::volume()
{
    return getLength() * getBreadth() * height;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    rectangle r1;
    cuboid c1;
    r1.setBreadth(10);
    r1.setLength(10);
    c1.setHeight(10);
    cout << c1.volume() << endl;

    return 0;
}