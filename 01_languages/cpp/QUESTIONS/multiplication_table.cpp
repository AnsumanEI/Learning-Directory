#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int n,i;
cout<<"enter the number whose table is wanted-->> " <<endl;
cin>>n;
cout<<"_________________" <<endl;
for(i=1;i<=10;i++)
{
    
    cout<<"|"<<n <<" X " <<i <<" = " <<n*i <<setw(1) <<"     |"  <<endl;
}
cout<<"_________________" <<endl;
return 0;
}