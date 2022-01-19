#include<iostream>
using namespace std;
typedef float numbers;
int main()
{
    numbers a,b,c;
cout<<"enter the value of first number :: " <<endl;
cin>>a;
cout<<"enter the value of second number :: " <<endl;
cin>>b;
cout<<"enter the value of third number :: " <<endl;
cin>>c;
if(a>b && a>c){
    cout<<"the greatest number between " << a <<" " << b <<" " << c << " is " <<a <<endl; 
}
else{
    if(b>c){
        cout<<"the greatest number between " << a <<" " << b <<" " << c << " is " <<b <<endl; 
    }
    else{
        cout<<"the greatest number between " << a <<" " << b <<" " << c << " is " <<c <<endl; 
    }
}
return 0;
}