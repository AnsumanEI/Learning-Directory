#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a[]={0,1,2,3,4,5,6,7,8,9,10};
int *p;
p=a;//as a is itself and address
cout<<p<<endl;
cout<<a<<endl;//as array itself is an adress
cout<<*a+2<<endl;
cout<<2[a]<<endl;
cout<<3[p]<<endl;
cout<<*a+1 <<" " <<*(a+1) <<endl;
for(int i=0;i<11;i++){
    cout<<*(p+i)<<endl;
    
}
return 0;
}