#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a[3][3]={
    {0,1,2},
    {3,4,5},
    {6,7,8}

    };

 int *p;
 p=*a;
 cout<<p<<endl;
 cout<<*a<<endl;
 cout<<*a+1<<endl;
 cout<<*(a+1)<<endl;
 cout<<a+1<<endl;
 cout<<*(*a+1)<<endl;

cout<<&a[1]+1<<endl;
cout<<*(a+2) + 0 <<endl;



return 0;
}