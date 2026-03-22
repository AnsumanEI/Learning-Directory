#include<iostream>
using namespace std;
int main()
{
    int num,a,rev=0;
cout<<"enter the number" <<endl;
cin>>num;
while(num>0) {
    a=num%10;
    // cout<<a <<endl;
    num=num/10;
    //  cout<<num <<endl;
    rev=rev*10 + a;     
}
cout<<"the new reversed number is " <<rev <<endl;
return 0;
}