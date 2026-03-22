#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
float call(int x[] , int size)
{
    int max=0;
    max=x[0];
    for(int i=0;i<size;i++)
    {
        if(x[i]>max)
        {
            max=x[i];
        }
    }
    return max;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int s;
cout<<"enter the size of the matrix "<<endl;
cin>>s;
int arr[s];
for(int i=0;i<s;i++)
{   cout<<"enter the " <<i+1 <<" number"<<endl;
    cin>>arr[i];
}
int maximum;
maximum=call(arr,s);
cout<<"maximum number is ";
cout<<maximum<<endl;

return 0;
}