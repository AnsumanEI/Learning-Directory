#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a[100]={1,2,3,4,5,6,7,8,9,10};
for(int i=10;i<=4;i--){
    a[i-1]=a[i];

}
a[3]=10;
for(auto x:a){
    cout<<x<<endl;
}
return 0;
}