#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
class test
{
    private:
    int a;
    int *p;
    public:
    test(int a=0)
    {
        this->a=a;
        cout<<a<<endl;
        p=new int[a];
    }
    
    //deep constructor 
    test(test &t1)
    {
        a=t1.a;
        p=new int[a];
        //so again a  new array is created for the deep copy constructor
    }
    int *testing(int x)
    {
        for(int i=0;i<x;i++)
        {
        *(p+i)=x+i;
        }
        return p;
    }
};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

//when we create a normal copy constructor it also points on the same array which is created by the constructor 
//but deep copy constructor creates a new array for itself
test t(20);
//calling deep copy
test t1(t);
cout<<t.testing(10)<<endl;
int *store;
store=t.testing(11);
cout<<store<<endl;
for(int i=0;i<11;i++)
{
    cout<<*(store+i)<<endl;
}
int *store1;

store1=t1.testing(111);
for(int i=0;i<11;i++)
{
    cout<<*(store1+i)<<endl;
}
return 0;
}