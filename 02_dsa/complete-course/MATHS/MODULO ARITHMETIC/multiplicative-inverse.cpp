#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
// same function to find out power
int pw(int a, int b, int m)
{
    if (b == 0)
        return a % m;
    long temp = pw(a, b / 2, m);
    if (b % 2 == 0)
    {
        return (temp * temp) % m;
    }
    else
    {
        return (a * temp * temp) % m;
    }
}
int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << (a / b) % m << " basic method " << endl;
    a %= m;
    // fermats little theorem for multiplicative inverse
    // works only when m is prime
    int inv_b = pw(b, m - 2, m);
    cout << (a * inv_b) % m << " using the formula " << endl;

    return 0;
}