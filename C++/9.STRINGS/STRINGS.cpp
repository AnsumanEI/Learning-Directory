#include<iostream>
using namespace std;
int main()
{
   
char s[]="hello";
char *p ="hello1";
char S[7]="hello2";

cout<<s <<endl;
cout<<S  <<endl;
cout<<*p <<endl;
cout<<*(p+2) <<endl;

return 0;
}