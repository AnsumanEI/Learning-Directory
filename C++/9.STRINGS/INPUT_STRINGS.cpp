#include<iostream>
using namespace std;
int main()
{
char S[100];
char S1[100];
char S2[100];

cout<<"enter your name -" <<endl;
cin.getline(S,50);
cout<<"hell0" <<endl;

cout<<"enter your name -" <<endl;
cin.get(S1,50);
cout<<"hell01" <<endl;

//to use multiple lines in get syntax we have to use the ignore syntax else it will take enter on the next character 
cin.ignore();

cout<<"enter your name -" <<endl;
cin.get(S2,50);
cout<<"hell02" <<endl;

return 0;
}