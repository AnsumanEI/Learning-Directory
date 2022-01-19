#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

template <class t>
t call(t x =0 , t y =0 , t z=0)
{
    return x>y && x>z ? x: y>z ? y:z;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a,b,c;

cout<<call(12,13,14)<<endl;
cout<<call(10,11)<<endl;
cout<<call(5)<<endl;
//no error is shown as default argument in the call function are set to 0
return 0;
}