#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
float call(int a[] , int x ,int size)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==x)
        {
            return i+1;
        }
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int A[10]={23,45,65,213,12,42,4,5,3,23};
cout<<"enter the number to find the address of "<<endl;
int key;
cin>>key;

if(call(A,key,10)>0)
{
    cout<<"the address is ";
 cout<<call(A,key,10);
}
else{
    cout<<"number is not found in the list";
}

return 0;
}