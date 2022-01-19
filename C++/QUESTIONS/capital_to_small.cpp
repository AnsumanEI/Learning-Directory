#include<iostream>
#include<cstring>

#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string str;
getline(cin,str);

string::iterator it;
for(it=str.begin();it!=str.end();it++){
    if(*it>=65&&*it<=90){
            *it=*it+32;
    }
    else if(*it>=97&&*it<=122){
        *it=*it-32;
    }
}

cout<<str<<endl;
return 0;
}