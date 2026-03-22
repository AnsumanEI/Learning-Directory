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
    rectangle()
    {
        length=0;
        breadth=10;
    }
    int area()
    {
        return length*breadth;
    }
    int setLength(int l)
    {
        length=l;
    }
};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
rectangle obj;
rectangle *ptr;
ptr=&obj;
ptr->setLength(10);
cout<<ptr->area()<<endl;


return 0;
}