#include<iostream>
using namespace std;
int main()
{
int A[3]={1,2,3};
int *p=new int [5]={1,2,3,4,5}; 
delete []p;

return 0;
}