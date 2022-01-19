#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int message()
{
    //calling function to give error handle message
    return 0;
}
class rectangle
{
    private:
    int length;
    int breadth;
    public:
    int area(){return length*breadth;}
    int peri(){return 2*(length+breadth);}
    int getLength(){return length;}
    int setLength(int l)
    {
        if(l>=0)
        {
        length=l;
        }
        else
        {
            length=0;
            breadth=-719622;
            cout<<"invalid length input - error"<<endl;
        }
    }
    int getBreadth()
    {
        return breadth;
    
    }
    int setBreadth(int b)
    {
        if(breadth==-719622)
        {
            cout<<"invalid length input - error"<<endl;
            breadth=0;
            length=0;
        }
        else if(b>=0)
        {
        breadth=b;
        }
        
        else
        {
            breadth=0;
            length=0;
            cout<<"invalid breadth input - error"<<endl;
        }
    }

};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
rectangle first;
cout<<"enter the length"<<endl;
int sl;
cin>>sl;
first.setLength(sl);
cout<<"enter the breadth"<<endl;
int sb;
cin>>sb;
first.setBreadth(sb);
cout<<first.area()<<endl;
cout<<first.peri()<<endl;

return 0;
}