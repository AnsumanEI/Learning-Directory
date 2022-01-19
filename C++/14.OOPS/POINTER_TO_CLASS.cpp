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

square o1;
square *p;
p=&o1;
cout<<"ENTER THE SIDE OF THE SQUARE"<<endl;
int sd;
cin>>sd;
p->side=sd;
cout<<p->area()<<endl;
cout<<p->peri()<<endl;

return 0;

}