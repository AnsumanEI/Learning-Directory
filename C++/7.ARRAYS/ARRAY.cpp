#include<iostream>
using namespace std;
int main()
{
int a[10]={12,323,234,5,23,213,23,245,76,45};
for(int i=0;i<10;i++){
    cout<<a[i] <<endl;
   cout <<endl;
}
//or
for(auto/*any type automatically check the type and gets it*/ &x:a){ //variable x for elements in a
    cout<<++x <<endl;
    //to modify the values inside the array we can use 
    // int &x:a ;
       
}


return 0;
}