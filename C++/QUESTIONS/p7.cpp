#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<climits>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t>0){
    int a[3];
    int b=0;
    
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    int max=a[0];
    
    for(int i=0;i<3;i++){
        if(a[i]>max){
            max=a[i];
            b=i;
        }
    }
    

    a[b]=0;
int max1=a[0];
    for(int j=0;j<3;j++){
        if(a[j]>max1){
            max1=a[j];
        }
    }
    cout<<max1<<endl;
    
t--;
}
return 0;
}