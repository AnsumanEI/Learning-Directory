#include<iostream>
using namespace std;
int main()
{
    int n,i,fact=1;
cout<<"enter the value of n " <<endl;
cin>>n;
for(i=1;i<=n;i++){
    fact*=i;
    cout<<fact <<endl;
}
if(n==1){
cout<<"the value of " <<n  <<"st" <<" factorial is " <<fact <<endl;
}
else if(n==2){
cout<<"the value of " <<n  <<"nd" <<" factorial is " <<fact <<endl;
}
else if(n==3){
cout<<"the value of " <<n  <<"rd" <<" factorial is " <<fact <<endl;
}
else {
cout<<"the value of " <<n  <<"th" <<" factorial is " <<fact <<endl;
}
return 0;
}