#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    float b = 0;
    cin >> b;
    float a = 100;
    try
    {
        if (b == 0)
        {
            throw 1;
        }
        cout << a / b << endl;
    }
    catch (int z)
    {
        cout << "please enter a valid no. instead of zero " << z << endl;
    }
    return 0;
}