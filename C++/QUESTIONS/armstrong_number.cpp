#include<iostream>
using namespace std;
int main()
{
    int num,a,sum=0,m;
    
cout<<"enter the number" <<endl;
cin>>num;
m=num;
// cout<<m <<endl;
while(num>0 ){
    a=num%10;
    sum=(a*a*a)+sum;
    // cout<<sum <<"......... sum ..........." <<endl;
    // cout<<a <<endl;
    num=num/10;
    
}
if(sum==m){
    // cout<<m;
    cout<<"it is an armstrong number" <<endl;

}
else{
    cout<<"it is not an armstrong number" <<endl;
}
return 0;
}