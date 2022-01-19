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
getline(cin,str);
int vl=0,ct=0,wd=1;
string::iterator it;
for(it=str.begin();it!=str.end();it++){
    if(*it>=65&&*it<=90){
        *it+=32;
    }

    if(*it==97||*it==101||*it==105||*it==111||*it==117){
        vl++;
    }
    else if(*it==32){
        wd++;
    }
    else{ct++;}
}
cout<<"vowels are "<<vl<<" consonants "<<ct<<" words are "<<wd<<endl;
return 0;
}