#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
class square
{
    public:
    int side;
    int area()
    {
        return side*side;
    }
    
    int peri()
    {
        return 4*side;
    }
};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
square *p=new square;
p->side=10;
cout<<p->area()<<endl;
cout<<p->peri()<<endl;
return 0;
}