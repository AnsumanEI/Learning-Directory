#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
template <class t>

t call(t x , t y )
{
    return x+y;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a,b,res;
cout<<"enter two numbers"<<endl;
cin>>a>>b;
res=call(a,b);
cout<<res<<endl;

return 0;
}