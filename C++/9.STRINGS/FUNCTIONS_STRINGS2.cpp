#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char a[20];

if(0)//change this to true to work
{
//getting chracter in strings
cout<<"enter a string" <<endl;

cin.get(a,20);
cin.ignore();
cout<<strchr(a,'n')<<endl;//takes first from left 
cout<<strrchr(a,'n')<<endl;//takes first from the right 

}

if(0)
{
    //string comparision
//if first letter ascii code is greater +1 will be printed 
//if same then 0 if less then negative
    char b[20],c[20];
    cout<<"enter b"<<endl;
    cin.get(b,20);
    cin.ignore();
    cout<<"enter c" <<endl;
    cin.get(c,20);
    cout<<strcmp(b,c)<<endl;

}
if(0){
    //string to float and long 
    char r[10]="12383493";
    char t[10]="123.23232";
    long x=strtol(r,NULL,10);//(string,ending,number system)
    float y=strtof(t,NULL);
    cout<<x <<" and " <<y <<endl;
}
if(0){
    //token
    char O[20]="a=20;b=30;c=40";
    char *token=strtok(O,";=");
    while(token!=NULL){
        cout<<token<<endl;
        token=strtok(NULL,";=");
    }


    
}

if(1){
    
}

return 0;
}