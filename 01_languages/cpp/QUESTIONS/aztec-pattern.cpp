#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    cout<<"pattern 1" <<endl;
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        if(i>=j){
            cout<<setw(2)<<" * " ;
        }
        else{
            cout<<"   ";
        }
    }
    cout<<endl;
}
cout<<"pattern 2" <<endl;
for(int i=0;i<4;++i){
    for(int j=0;j<4;++j){
        if(i<=j){
            cout<<setw(3)<<" * " ;
        }
        else{
            cout<<setw(3)<<"   ";
        }
    }
    cout<<endl;
}
cout<<"pattern 3" <<endl;
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        if(i+j>=3){
            cout<<" * ";
        }
        else{
            cout<<"   ";
        }
    }
    cout<<endl;
}

cout<<"pattern 4" <<endl;
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        if(i+j<=3){
            cout<<" * ";
        }
        else{
            cout<<"   ";
        }
    }
    cout<<endl;
}

return 0;
}