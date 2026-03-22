#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    int ans;
    int temp;
    int digit = 1;
    cin >> a >> b;
    ans = a - b;
    temp = ans;
    while (temp > 10)
    {
        temp /= 10;
        digit++;
    }

    if (digit > 1)
    {
        ans = ans + pow(10, digit - 2);
    }
    else if (ans == 0)
    {
        ans += 1;
    }
    else
    {
        if (ans == 9)
        {
            ans -= 1;
        }
        else
        {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}