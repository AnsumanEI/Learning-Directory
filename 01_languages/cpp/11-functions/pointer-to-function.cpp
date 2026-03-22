#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int call(int x , int y)
{   
    
    return 719;
}
int min(int x,int y)
{
    return 5;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int (*pf)(int , int);
pf=call;
cout<<(*pf)(10,5)<<endl;

pf=min;
cout<<(*pf)(11,5)<<endl;




return 0;
}