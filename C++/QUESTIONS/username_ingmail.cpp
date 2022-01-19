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
cout<<"enter the gmail "<<endl;
getline(cin,str);
int ad=0;

string::iterator it;
for(it=str.begin();it!=str.end();it++){

    if((*it>=64&&*it<=90)||(*it>=97&&*it<=122)||(*it>=48&&*it<=57)){

      ad=str.find_first_of('@');

    }
    else{
        *it=32;
    }
}
cout<<"username is -> "<<str.substr(0,ad);


return 0;
}