#include<iostream>
using namespace std;
int main()
{
    int num,i,sum=0;
cout<<"enter the number " <<endl;
cin>>num;
for(i=1;i<=num;i++)
{
    if(num%i==0){
        cout<<"factors are " <<i <<endl;
        sum=sum+i;
        
    }
   
}
 cout<<"the sum of the factors are " <<sum <<endl;
return 0;
}