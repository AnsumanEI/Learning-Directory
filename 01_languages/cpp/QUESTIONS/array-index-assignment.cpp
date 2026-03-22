#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string odd="1,3,5";
string even="2,4,6";
string res;
int a[1]={1};
int b[3]={1,2,2};
int c[4];
a[0]=b[1];
cout<<a[0]<<endl;
return 0;
}