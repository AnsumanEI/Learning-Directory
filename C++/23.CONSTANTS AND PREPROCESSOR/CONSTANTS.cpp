#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int a = 10;
    int b = 20;
    int d = 40;
    // a++; not possible as constants can not be modified
    // pointer to integer constants
    const int *ptr;
    ptr = &b;
    cout << *ptr << endl;
    // we can change the pointer to point on to some other variables
    ptr = &d;
    // ++*ptr; not allowed as the pointer can read the value but cannot modify it  as it is an constant
    // constant pointer to integer
    int c = 30;
    int *const ptr1 = &c;
    // can modify the value of c
    // cannot point to some other variables through this pointer as the pointer is constant
    cout << ++*ptr1 << "constant pointer to integer ";
    // constant pointer to integer constant
    int e = 50;
    const int *const ptr2 = &e;
    // as the integer and the pointer are both constant so
    //  we cannot modify the data or we cannot point to some other variable through that pointer
    //++*ptr2;
    // ptr2=&d;
    // the above both are not possible

    return 0;
}