include<iostream>
#include<string.h>
using namespace std;
int main()
{
//string length
char A[100];
cout<<"enter the first string " <<endl;
cin.getline(A,100);

cout<<strlen(A)<<endl;

//concatenation or linking of two strings
char B[100];
cout<<"enter a second string " <<endl;
cin.getline(B,100);

strcat(A,B);
cout<<A <<endl;

char C[100]="hello ";
strncat(C,A,20);
cout<<C <<endl;

//string copy
char D[100];
strncpy(D,C,100);
cout<<D<<endl;

//substring finding 

if(strstr(A,B)!=NULL){
    cout<<strstr(A,B) <<endl;
}
else{
    cout<<"not found" <<endl;
}

return 0;
}
