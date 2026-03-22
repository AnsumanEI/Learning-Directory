#include<iostream>
#include<math.h>
using namespace std;
int main()
{
//finding the root of quadratic equations
float a,b,c,x,y;//x and y are 2 roots
cout<<"enter the value of coefficient a :"<<endl;
cin>>a;
cout<<"enter the value of coefficient b :"<<endl;
cin>>b;
cout<<"enter the value of coefficient c:"<<endl;
cin>>c;
cout<<endl;
//expression conversion
x=((-b)+sqrt(b*b-4*a*c))/(2*a);
y=((-b)-sqrt(b*b-4*a*c))/(2*a);
cout<<"the value of 2 roots satisfying the equations are :: " <<x <<" and " <<y <<endl;

return 0;
}