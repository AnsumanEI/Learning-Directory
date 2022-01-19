#include<iostream>
using namespace std;
int main()
{
    int n,sum=0,i;
cout<<"enter the nth number" <<endl;
cin>>n;
for(i=1;i<=n;i++){
    sum=sum+i;
   
    // cout<<sum <<endl;
}
cout<<"the sum is " <<sum <<endl;
return 0;
}