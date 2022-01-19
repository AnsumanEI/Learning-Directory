#include<iostream>
using namespace std;
int main()
{
int a=7,b=4,c=8,d=8;
//short circuit = true
if(a<b && ++d>c){
  // anything i write here does not matter as it will not proceeed inside the bracker and the function will not be implemented
}
cout<<d <<endl;
//same d value as first function does the short circuit 

//short circui = false

if(a>b && ++d>c)
{
cout<<d <<endl; //the value of d must be printed 9 as the first funtion allows the value to operate
}

return 0;
}