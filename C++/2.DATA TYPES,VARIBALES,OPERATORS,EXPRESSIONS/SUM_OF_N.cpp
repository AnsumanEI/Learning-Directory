#include<iostream>
using namespace std;
int main()
{
int sum=0,val,val2,val1;
cout<<"enter the starting number" <<endl;
cin >> val;
val1=val;

cout<<"enter the ending number" <<endl;
cin >> val2;

while(val<=val2){
    sum+=val; //sum + val =sum
    ++val;

}
cout<<"the sum of number from "<<val1 <<" to " <<val2 <<" is " << sum <<endl;
return 0; 
}