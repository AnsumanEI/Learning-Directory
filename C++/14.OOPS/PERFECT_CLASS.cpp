#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
class rectangle
{
    private:
    int length;
    int breadth;
    public:
    //constructors
    
    rectangle(int l=0,int b=0)
    {
        length=l;
        breadth=b;
    }
    rectangle(rectangle &r)
    {
        length=r.length;
        breadth=r.breadth;
    }
    //facilitators
    int area()
    {
        return length*breadth;
    }
    int perimeter()
    {
        return 2*(length+breadth);
    }
    //accesors and mutators
    int setLength(int x)
    {
        if(x<0)
        {
            length=0;
            breadth=100102;
        }
        else
        {
            length=x;
        }
    }
    int getLength()
    {
        return length;
    }
    int setBreadth(int y)
    {
        if(y<0||breadth==100102)
        {
            breadth=0;
        }
        else
        {
            breadth=y;
        }
    }
    int getBreadth()
    {
        return breadth;
    }
    bool isSquare();
    ~rectangle();
    
};
bool rectangle::isSquare()
{
    return length==breadth;
}
rectangle::~rectangle()
{
    cout<<"rectangle destroyed";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

rectangle obj;
obj.setBreadth(10);
obj.setLength(10);
cout<<obj.area()<<endl;
cout<<obj.perimeter()<<endl;
if(obj.isSquare())
{
    cout<<"it is a square";
}

return 0;
}