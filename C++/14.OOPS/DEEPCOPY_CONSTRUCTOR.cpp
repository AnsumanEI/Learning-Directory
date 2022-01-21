#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
class test
{
    int a;
    int *p;
    test(int a)
    {
        this->a=a;
        p=new int[a];
    }
    //normal copy constructor
    test(test &t)
    {
        a=t.a;
        p=t.p;
    }
    //deep constructor 
    test(test &t1)
    {
        a=t1.a;
        p=new int[a];
        //so again a  new array is created for the deep copy constructor
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
test obj(5);
//when we create a normal copy constructor it also points on the same array which is created by the constructor 
//but deep copy constructor creates a new array for itself

return 0;
}