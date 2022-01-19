#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,win;
cin>>n;
int diff=0,lead=0;
int sum1=1,sum2=0;
for(int i=0;i<n;i++){
    int p1,p2;
    cin>>p1>>p2;
    sum1+=p1;
    sum2+=p2;
    if(sum1>sum2){
         diff=sum1-sum2;
         if(diff>lead){
             lead=diff;
             win=1;
         }
    }
    else{
        diff=sum2-sum1;
        if(diff>lead){
            lead=diff;
            win=2;
        }
    }
}
cout<<win<<" "<<lead;
return 0;
}