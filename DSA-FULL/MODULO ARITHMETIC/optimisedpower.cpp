#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int power(int a, int b, int m)
{
    if (b == 0)
    {
        return a % m;
    }
    if (b % 2 == 0)
    {
        int temp = power(a, b / 2, m);
        return (1ll * temp * temp % m);
    }

    else
    {
        int temp = power(a, (b - 1) / 2, m);
        temp = (1ll * temp * temp) % m;
        return (1ll * a * temp) % m;
    }
}

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << power(a, b, m) << endl;
    return 0;
}