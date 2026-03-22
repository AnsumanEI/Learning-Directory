#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
//call by address
void swap(int *x , int *y)
{
   int temp=*x;
   *x=*y;
   *y=temp;
   //values are changed in main functions as x and y are pointers to a and b
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout<<"enter two numbers to swap"<<endl;
int a,b;
cin>>a>>b;
swap(&a,&b);
cout<<a<<" "<<b<<endl;

return 0;
}