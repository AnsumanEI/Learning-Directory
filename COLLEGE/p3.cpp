#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int *a=new int [10];
for(int i=0;i<10;i++)
{
    cout<<"enter "<<i<<endl;
    cin>>a[i];
}
cout<<a<<endl;

return 0;
}