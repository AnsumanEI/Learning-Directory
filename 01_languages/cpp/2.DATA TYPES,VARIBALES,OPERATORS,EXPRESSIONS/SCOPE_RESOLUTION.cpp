#include<iostream>
using namespace std;
//how to call global variables
int num1=10;
int main()
{
int num1=20,num2=40;
int sum;
sum=num1+num2;
cout<<"the sum of " <<num1 <<" and " <<num2 <<" is " <<sum <<"." << endl;
cout<<"the local variable num 1 = " << num1 <<endl;
cout<<"the global variable num 1 = " <<::num1 <<endl; //this scope resolution operator is used to call global variables into local one
//if decimal numbers are called normallly they are doubles to specify them as float we have to write 34.4f , 45.6f etc
cout<<endl;
cout<<endl;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
float c=34.4;
cout<<endl;
float d=34.4f;
cout<<endl;
long double e=34.4l;
//double is taken by default so not mentioned
cout<<endl;
cout<< "the value of 34.4f : " <<sizeof(d) <<endl;
cout<< "the value of 34.4l : " <<sizeof(e) <<endl;
cout<< "the value of 34.4 : " <<sizeof(34.4) <<endl;



return 0;
}