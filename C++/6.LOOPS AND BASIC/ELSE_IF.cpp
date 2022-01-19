#include<iostream>
using namespace std;
int main()
{
    int day;
cout<<"enter the day number:" <<endl;
cin>>day;

if(day==1){
    cout<<"the day is monday" <<endl;
}
else if(day==2){
    cout<<"the day is tuesday" <<endl;
}
else if(day==3){
    cout<<"the day is wednesday" <<endl;
}
else if(day==4){
    cout<<"the day is thursday" <<endl;
}
else if(day==5){
    cout<<"the day is friday" <<endl;
}
else if(day==6){
    cout<<"the day saturday" <<endl;
}
else if(day==7){
    cout<<"the day is sunday" <<endl;
    
}
else{
    cout<<"invalid day , please enter a valid no. for days"<<endl;
}
cout<<day<<endl;
return 0;
}