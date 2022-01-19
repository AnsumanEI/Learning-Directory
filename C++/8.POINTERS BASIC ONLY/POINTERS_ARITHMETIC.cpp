#include<iostream>
using namespace std;
int main()
{
int A[5]={1,2,3,4,5};
int *p=A;
int n=0;
//operations allowed in pointers
//1.p++ it will move to the next address of the pointing data
//2.p--
//3.p=p+2 it means it will move forward by two address/elements
//4.p=p-2
//5.distance btwn two pointer d=p-q the result is divided by the size of data type 
// cout<<*p<<endl;
// p++;
// cout<<*p<<endl;
// p=p+3;
// cout<<*p <<endl;
cout<<"printing the array through pointers " <<endl;
while(n<5)
{
    cout<<*p<<endl;
    p++;
    n++;
}
return 0;
}