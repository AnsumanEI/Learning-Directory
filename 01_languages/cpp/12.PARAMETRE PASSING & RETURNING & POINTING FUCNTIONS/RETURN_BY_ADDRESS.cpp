#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int *call(int size)
{
    int *p=new int [size];
    for(int i=0;i<=size;i++)
    {
        p[i]=i+1;
    }
    cout<<p<<endl;//p has address of the array in the heap
    cout<<&p<<" 1 "<<endl;
    return p;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cout<<call(10)<<" 2 "<<endl;
int *ptr=call(10);
ptr[5]={200};//edited the heap within the main with the help of pointer
for(int j=0;j<10;j++)
{
    cout<<ptr[j]<<endl;
}



return 0;
}