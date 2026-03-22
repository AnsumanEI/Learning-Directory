#include<iostream>
using namespace std;
int main()
{
    
int a[]={11,2,3,4,455,1,7,8,9,1};
int max=a[0];
for(int i=1 ; i<10 ;i++){
   
   
//    cout<<max <<"max" <<endl;
//    cout<<i  <<"i value"<<endl;
   if(a[i] > max){
       max=a[i];
   }
   
}
cout<<max <<" it is the maximum value in the array" <<endl;
return 0;
}