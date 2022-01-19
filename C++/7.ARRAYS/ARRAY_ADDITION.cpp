#include<iostream>
using namespace std;
int main()
{
    int sum=0;
int a[]={2,4,6,8,10,12,24,30};
for(auto x:a){
    
    sum=sum+x;

}
cout<<"the sum is " <<sum <<endl;
return 0;
}