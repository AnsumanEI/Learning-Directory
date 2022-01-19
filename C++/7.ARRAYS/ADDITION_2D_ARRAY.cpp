#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    typedef int rowandcol;
    typedef int twodarray;
    rowandcol r=0,c=0,q=0,e=0;
    
    cout<<"enter the value of rows and columns"<<endl;
    cin>>r>>c;
    twodarray A[r][c];
    twodarray B[q][e];
    twodarray C[r][c];
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
       
        cout<<"enter the number corresponding to " <<"("<<i<<","<<j <<")"<<endl;
        cin>>A[i][j];
    }
}

cout<<"now the second matrix"
<<endl;

    
    cout<<"enter the value of rows and columns"<<endl;
    cin>>q>>e;
   
for(int i=0;i<q;i++){
    for(int j=0;j<e;j++){
       
        cout<<"enter the number corresponding to " <<"("<<i<<","<<j <<")"<<endl;
        cin>>B[i][j];
    }
}

cout<<"1st matrix is as follows " <<endl;

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
       
        cout<<setw(2)<<A[i][j] <<" ";
        
    }
    cout<<endl;
}


cout<<"2nd matrix is as follows " <<endl;

for(int i=0;i<q;i++){
    for(int j=0;j<e;j++){
       
        cout<<setw(2)<<B[i][j] <<" ";
        
    }
    cout<<endl;
}

if(q==r && e==c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            C[i][j]= A[i][j] + B[i][j];
            
        }
    }
    
    for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cout<<"the sum of the matrix is -" <<endl;
        cout<<C[i][j] <<" ";
    }
    cout<<endl;
}
}
else{
    cout<<"both matrices should have equal dimensions" <<endl;
}




return 0;
}