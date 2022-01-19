#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
class rectangle
{
    public://as by default class is private

    int length;
    int breadth;
    int area()
    {
        return length*breadth;
    }
    int perimetre()
    {
        return 2*(length+breadth);
    }
};

int hello()
{
    return 10;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

rectangle r1,r2;//object created
r1.length=10;
r1.breadth=90;
cout<<r1.area()<<endl;
r2.length=30;
r2.breadth=10;
cout<<r2.area()<<endl;
cout<<r1.perimetre()<<endl;
cout<<r2.perimetre()<<endl;

cout<<hello();
return 0;

}