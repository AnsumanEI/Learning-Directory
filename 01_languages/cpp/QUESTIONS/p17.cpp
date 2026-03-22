#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int *test(int x)
{
    int *p=new int[x];
    int i=x;
     for(int i=0;i<=x;i++)
    {
        p[i]=i+1;
    }
    cout<<p<<" h "<<endl;
    return p;
    
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int *ptr=test(10);
cout<<ptr<<endl;
cout<<ptr[7]<<endl;
*(ptr+7)={100};
//or
ptr[7]=100;
cout<<ptr[7]<<endl;




return 0;
}