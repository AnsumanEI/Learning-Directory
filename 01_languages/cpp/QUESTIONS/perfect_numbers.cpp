#include<iostream>
using namespace std;
int main()
{
    int i , n , sum=0;
cout<<"enter the number to check " <<endl;
cin>>n;
for(i=1;i<=n;i++)
{
    if(n%i==0){
        
        sum=sum+i;
    }
}
// cout<<sum <<endl;
if(sum==2*n){
    cout<<"the number is a perfect  number" <<endl;
}
else{
    cout<<"the number is not a perfect number" <<endl;
}
return 0;
}