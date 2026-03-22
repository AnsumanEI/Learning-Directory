#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

void func(int x)
{
    if(x==1)
    {
        cout<<x<<endl;
    }
    else
    {
        func(x-1);
        cout<<x<<endl;
    }
}

void rev(int x)
{
   if(x==1)
   {
       cout<<x<<endl;
   }
   else
   {
       cout<<x<<endl;
       rev(x-1);
   }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cout<<"enter the value of n"<<endl;
cin>>n;
void (*ptr)(int);
ptr=func;
(*ptr)(n);
cout<<endl;
ptr=rev;
(*ptr)(n);


return 0;
}