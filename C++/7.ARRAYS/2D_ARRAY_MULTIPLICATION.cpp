#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{


int r1=0,c1=0,r2=0,c2=02,k=0;
int A[10][10];
int B[10][10];
int C[10][10];
cout<<"for matrix 1 enter the no. of rows and columns" <<endl;
cin>>r1>>c1;

for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
        cout<<"enter the value of A("<<i+1 <<","<<j+1 <<")" <<endl;
        
        cin>>A[i][j];  
    }
}

cout<<"for matrix 2 enter the no. of rows and columns" <<endl;
cin>>r2>>c2;

for(int i=0;i<r2;i++){
    for(int j=0;j<c2;j++){
        cout<<"enter the value of B("<<i+1 <<","<<j+1 <<")" <<endl;
        cin>>B[i][j];  
    }
}

//multiplication part
if(c1==r2){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            C[i][j]=0;
            for(int k=0;k<c1;k++){
            C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
cout<<"the answer of the multiplication matrix is " <<endl;
 
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
           
            cout<<setw(2)<<C[i][j]<<" " ;
        }
        cout<<endl;
      
    }
}

else{
    cout<<"enter the rows of matrix two and column of matrix one same and try again later" ;
}
  return 0;
}