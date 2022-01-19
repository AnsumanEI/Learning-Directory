#include<iostream>
using namespace std;
int main()
{
int m,n;
cout<<"enter the value of m" <<endl;
cin>>m;
cout<<"enter the value of n" <<endl;
cin>>n;
while(m!=n){
    if(m>n){
        m=m-n;
    }

else{
    n=n-m;
}    
}
cout<<"the gcd of the numbers is " <<m   <<endl;

return 0;
}