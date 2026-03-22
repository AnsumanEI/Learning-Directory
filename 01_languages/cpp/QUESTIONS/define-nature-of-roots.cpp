#include<iostream>
using namespace std;
typedef int coefficient;
int main()
{
    coefficient a,b,c;
    cout<<"enter the value of first coefficient :->" <<endl;
    cin>>a;
    cout<<"enter the value of second coefficient :->" <<endl;
    cin>>b;
    cout<<"enter the value of third coefficient :->" <<endl;
    cin>>c;

    if(((b*b)-(4*a*c))>0){
        cout<<"the roots are real and unequal" <<endl;
    }
    else{
        if(((b*b)-(4*a*c))<0){
            cout<<"the roots are imaginary" <<endl;
        }
        else{
            cout<<"the roots are real and equal" <<endl;
        }
    }
return 0;
}