#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#define pi 3.1417689
using namespace std;
class circle
{
    private:
    int radius;
    public:
    circle(int radius)
    {
       setRadius(radius);
    }
    int setRadius(int radius)
    {
        this->radius=radius;//this radius means the main object radius and the normal one means the one in the constructor
    }
    float area();
};
float circle::area()
{
    return pi*radius*radius;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
circle c(10);
cout<<c.area()<<endl;

return 0;
}