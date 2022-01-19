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
    //parameterised
    // rectangle 
    // 
    //     length=0;
    //     breadth=0;
    // 
    rectangle(int x=1, int y=1)//in absence of arguments it will take input as the default arguments will be called
    {
        setLength(x);
        setBreadth(y);
    }
    //copy constructor
    rectangle(rectangle &r)
    {
        length=r.length;
        breadth=r.breadth;
    }
    int area()
    {
        return length*breadth;
    }
    int peri()
    {
        return 2*(length+breadth);
    }
    int getLength()
    {
        return length;
    }
    int getBreadth()
    {
        return breadth;
    }
    int setLength(int l)
    {
        if(l>0)
        {
        length=l;
        }
        else
        {
            length=0;
            breadth=0;
        }
    }
    int setBreadth(int b)
    {
        if(b>0)
        {
        breadth=b;
        }
        else if(length==0)
        {
           breadth=0;
        }
        
    }
    
};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

rectangle rect;
cout<<rect.area()<<endl;
rectangle rect1(10,50);
cout<<rect1.area()<<endl;
rectangle rect2(rect1);
cout<<rect2.area()<<endl;
return 0;
}