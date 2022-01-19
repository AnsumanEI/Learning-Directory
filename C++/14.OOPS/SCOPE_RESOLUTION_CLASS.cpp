#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
//FUNCTIONS INSIDE THE CLASS ARE INLINE FUNCTIONS SO , COMPLES LOGIC SHOULD NOT BE USED SO SCOPE 
//RESOLUTION IS USED TO WRITE IT OUTSIDE THE FUNCTION
//INLINE FUNCTIONS ARE INSIDE MAIN FUNCTIONS ONLY SO SCOPE RESOLUTION IS A BETTER OPTION
class square
{
    private:
    int length;
    public:
    int setLength(int x)
    {
        length=x;
    }
    int area()//inline functions 
    {
        return length*length;
    }
    int perimeter();
    ~square();
};
//function using scope resolution and its not a part of the main function
square::~square()
{
   cout<<"square destroyed";
}
int square::perimeter()
{
    return 4*length;
}
int main()
{
//if we write inline before the function and write the function outside the class it is made inline
ios_base::sync_with_stdio(false);
cin.tie(NULL);
square s;
square *p;
p=&s;
p->setLength(10);
cout<<p->area()<<endl;
cout<<p->perimeter()<<endl;
return 0;
}