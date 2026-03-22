#include<iostream>
using namespace std;
int a,b,option;
int main()
{

cout<<"MENU" <<endl;
cout<<"1.Add \n" <<"2.Sub \n" <<"3.Div \n" <<"4.Mul \n" <<endl;
cin>>option;
if(option<5){
cout<<"enter first number" <<endl;
cin>>a;
cout<<"enter 2nd number" <<endl;
cin>>b;
switch (option)
{
case 1: cout<<"{"<<a+b <<"}";
    break;
case 2: cout<<"{"<<a-b <<"}";
    break;
case 3: cout<<"{"<<a/b <<"}";
    break;  
case 4: cout<<"{"<<a*b <<"}";
    break;      
default: cout<<"enter a valid number";
    break;
}
}
else {
    cout<<"enter a valid option";
}
return 0;
}