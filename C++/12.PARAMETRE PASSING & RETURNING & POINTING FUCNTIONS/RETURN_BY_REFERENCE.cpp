#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int &call(int &x)
{
    int a;
    a=10;
    x=a;
    return x;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int b=100;
cout<<call(b);
//value of call is now equal to b and can be edited as we can see that the 100 is changed ot 10 by the return of the reference

return 0;
}