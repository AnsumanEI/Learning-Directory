#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int sum(int x,int y){
    int z;
    z=x+y;
    return z;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a,b;
float res=0;
cout<<"enter two numbers"<<endl;
cin>>a>>b;
res=sum(a,b);
cout<<"the result is "<<res<<endl;



return 0;
}