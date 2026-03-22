#include<iostream>
using namespace std;

int main()
{

int a[]={34,45,67,56,34,56,23,53,64};
int key;
cout<<"enter the marks you want to find " <<endl;
cin>>key;

for(int i=0;i<10;i++){
    if(a[i]==key){
        cout<<"the address for the searched element is " <<i <<endl;
        return 0;
    }
    
}
cout<<"unsucessfull" <<endl;
}