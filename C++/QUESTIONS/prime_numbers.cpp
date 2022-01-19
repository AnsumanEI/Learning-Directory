#include<iostream>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n=0,k=0,c=0;
cin>>n>>k;
int t[n];
for(int i=0;i<n;i++){
    cin>>t[i];
    if(t[i]%k==0){
        c++;
    }

}
cout<<c<<endl;
return 0;
}