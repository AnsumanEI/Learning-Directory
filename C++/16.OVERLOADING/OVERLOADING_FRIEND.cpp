#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
class complex
{
    public:
    int real;
    int img;
    complex(int real=0,int img=0)
    {
        this->real=real;
        this->img=img;
    }
    //declaration of friend function which takes both objects and adds them then returns it 
    //but the member overloading only takes one adds using it then returns the sum
    friend complex operator+(complex x,complex y);
};

//mandatory to write it outside the class 
complex operator+(complex x,complex y)
{
   complex temp;
   temp.real=x.real + y.real;
   temp.img=x.img + y.img;
   return temp;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int c,i,ca,ia;
cout<<"enter value of the 1st complex and imaginary part"<<endl;
cin>>c>>i;
cout<<"enter value of the 2nd complex and imaginary part"<<endl;
cin>>ca>>ia;


complex c1(c,i);
complex c2(ca,ia);
complex c3;
c3=c1+c2;
cout<<c3.real<<" + i"<<c3.img<<endl;
return 0;
}