#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin>>T;
    while(T!=0){
        int sum=0;
        int N;
        cin>>N;
        while(N!=0){
        int a;
        a=N%10;
        sum+=a;
        N=N/10;
        }
        cout<<sum<<endl;
        T--;
    }
   

return 0;
}