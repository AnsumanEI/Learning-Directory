#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a[50]={1,2,3,5,6,7,8,9,10};
cout<<"before adding 4 to the array " <<endl;
for(int i=0;i<10;i++){
    cout<<a[i] <<endl;
}

for(int i=10;i>=3;i--){
    a[i+1]=a[i];
    

}
a[3]={4};
cout<<"after ordered shifting " <<endl;
for(int i=0;i<10;i++){
    cout<<a[i] <<endl;
}
return 0;
}