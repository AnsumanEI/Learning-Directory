#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int call(int base)
{
    if (base < 4)
    {
        return 0;
    }
    else
    {
        int temp = 0;
        int square = 0;
        temp = (base / 2) - 1;
        for (int i = 1; i <= temp; i++)
        {
            square += i;
        }
        return square;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int b;
        cin >> b;
        cout << call(b) << endl;
    }
    return 0;
}