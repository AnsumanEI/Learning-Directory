#include<iostream>
using namespace std;
typedef int marks;
typedef float average;
int main()
{
marks m1,m2,m3;
average avg;

cout<<"enter the marks in subject 1 :" <<endl;
cin>>m1;
cout<<"enter the marks in subject 2 :" <<endl;
cin>>m2;
cout<<"enter the marks in subject 3 :" <<endl;
cin>>m3;
avg=(m1+m2+m3)/3;

if(m1<=80&&m2<=80&&m3<=80)
{
    
    if(avg>=70)
    {
    cout<<"the grade obtained by the student is :: A " <<endl;
    }
    else if(avg>=55)
    {
    cout<<"the grade obtained by the student is :: B " <<endl;
    }
    else{
        cout<<"the grade obtained by the student is :: C " <<endl;
    }
}
else{
    cout<<"please enter a valid mark and start the programm again" <<endl;
}
return 0;
}