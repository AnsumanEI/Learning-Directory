#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
//overloading of insertion and extraction operators using friend funtion
class complex
{
    int real;
    int img;
    public:
    complex(int real=0,int img=0)
    {
        this->real=real;
        this->img=img;
    }
    
};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}