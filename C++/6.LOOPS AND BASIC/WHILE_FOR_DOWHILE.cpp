#include<iostream>
using namespace std;
int main()
{
    int a=1,b=11,c=12,d=13,e=10;
//loops are of four type
//while
//do while
//for 
//for each 
while(d>a)
{
    ++a;
    b+=a;
    cout<<a <<endl;
}
if(a>d){
    cout<<"value" <<a <<endl;
}
else{cout<<a <<" process id complete" <<endl;}

// do while

do{
    
    ++e;
    cout<<e <<endl;
}
while(e<100);
return 0;
}