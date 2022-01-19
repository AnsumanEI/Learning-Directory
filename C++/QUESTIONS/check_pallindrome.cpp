#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string str;
cout<<"enter a string to check"<<endl;
getline(cin,str);
string rev="";
int len=0;
str.length();


string::reverse_iterator it;
for(it=str.rbegin();it!=str.rend();it++){
    rev+=*it;
}
len=rev.length();
rev[len]='\0';
cout<<"rev= "<<rev<<endl;
if(str.compare(rev)==0){cout<<"pallindrome"<<endl;}
else{cout<<"not a pallindrome"<<endl;}
return 0;
}