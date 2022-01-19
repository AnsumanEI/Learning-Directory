#include<iostream>
using namespace std;
int main()
{
//instead of decalaring variable in the main function we can declare it inside the function we want so that it gets removed when the function is over 
int a; //uses more memory 

if(11>9){
    int b=9;//get removed after the if function is over 
    cout<<b <<endl;
    

}
// else if(int c=21;c>){
//     cout<<"hello" <<endl;
// }
//only for cpp version 17
return 0;
}