#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int testcase;
cin>>testcase;
while(testcase>0)
{
    string str;
    cin>>str;
    int len=0;
    len=str.length();
    if(len==1)
    {
        cout<<"no"<<endl;
        
    }
    else{
    int count=0,pos=0;
    for(int i=0;i<=len;i++)
    {
        if(str[i]=='1'){count++;pos=i;}
    }
    if((count==0)||(count==1&&pos==len)){cout<<"no"<<endl;}
    else{cout<<"yes"<<endl;}
    }
    testcase--;
}
return 0;
}