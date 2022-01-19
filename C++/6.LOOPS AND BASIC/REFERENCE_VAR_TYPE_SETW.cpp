#include<iostream>
#include<iomanip> //for setw manipulators

using namespace std;
//REFRENCE VARIABLE AND TYPE CASTING
int main()
{
int a =100;
int &b=a; //so now b and a are the same thing with diffrent names
cout<<"calling out both a and b " <<endl;
cout<<"the value of a is "<<a <<endl;
cout<<"the value of b is "<<b <<endl;
//***********************************************************************************************
cout<<endl;
cout<<endl;
cout<<"type casting " <<endl;
float num =24.4;
cout<<"the real value of num is float " <<num <<endl;

cout<<"typecasting means changing the form of number like value of num is now integer printed " <<int(num) <<endl;

//how to make constantstring
const int r=45;
//now the value of r will not change


//***************************
//manipulators
int x =1 ,y =12 ,  z=123, p=1234 ;
cout<<"the value of x without setw : " <<x <<endl;
cout<<"the value of y without setw : " <<y <<endl;
cout<<"the value of z without setw : " <<z <<endl;
cout<<"the value of p without setw : " <<p <<endl;

cout<<endl;

cout<<"the value of x with setw : "<<setw(4) <<x <<endl;
cout<<"the value of y with setw : "<<setw(4) <<y <<endl;
cout<<"the value of z with setw : "<<setw(4) <<z <<endl;
cout<<"the value of p with setw : "<<setw(4) <<p <<endl;




return 0;
}