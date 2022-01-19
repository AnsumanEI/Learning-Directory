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
string::reverse_iterator it;
for(it=str.rbegin();it!=str.rend();it++){
    cout<<*it;
}

return 0;
}