#include<iostream>
using namespace std;
int main()
{

int a=10;
int *p;
p=&a;
cout<<a<<endl;
cout<<&a<<endl; //adress of a is printed
cout<<p<<endl;//value of p is printed which stored the adress of variable a
cout<<&p<<endl;//adress of adress variable p is shown
cout<<*p<<endl;//it shows the data inside the variable towards which it is pointing in this case it is a 
return 0;
}