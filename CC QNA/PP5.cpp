#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int fact;
        int store = 0;
        cin >> fact;
        while (fact % 5 != 0)
        {
            fact--;
        }

        while (fact / 5 != 0)
        {
            store += (fact / 5);
            fact /= 5;
        }
        cout << store << endl;
    }

    return 0;
}