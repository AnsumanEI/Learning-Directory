#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int divisions(int x, int y)
{
    if (y == 0)
    {
        throw 1;
    }
    else
    {
        return x / y;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num1;
    int num2;
    cin >> num1 >> num2;

    try
    {
        int div;
        div = divisions(num1, num2);
        cout << div << endl;
    }
    catch (int z)
    {
        cout << "enter a valid number" << z << endl;
    }
    return 0;
}