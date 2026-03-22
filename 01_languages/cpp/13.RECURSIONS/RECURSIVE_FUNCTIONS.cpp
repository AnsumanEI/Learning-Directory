#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
long long int call(long long int n)
{
    if(n<=1)
    {
        return 1;
    }

    else
    {
        return call(n-1)*n;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cout<<"enter the number to find factorial of" <<endl;
int a;
cin>>a;
cout<<"the factorial of " <<a<<" = "<<call(a)<<endl;




return 0;
}