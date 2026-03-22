#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class outer
{
public:
    int a;
    static int b;
    void func()
    {
        inner bbs;
        bbs.c = 10;
        // cout<<c<<endl;//cannot access inner class directly
    }
    class inner
    {
    public:
        int c = 100;
        void display()
        {
            outer ans;
            ans.b = 10;
            ans.a = 100;
            // cout<<a<<endl;//cannot access non static members
            cout << b << endl; // can access static members directly
        }
    };
};
int outer::b = 10;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}