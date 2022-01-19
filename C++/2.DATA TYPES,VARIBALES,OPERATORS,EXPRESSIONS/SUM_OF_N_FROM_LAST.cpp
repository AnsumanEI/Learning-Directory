#include<iostream>
using namespace std;
int main()
{
int sum = 0, val;
cout<<"enter the last number for sum: " <<endl ;
cin>>val ;
while (val>0){
    sum+=val;
    --val;
    //cout<<val<<endl;       
}
cout<<"the total value after sum is :" <<sum <<endl;
return 0;
}