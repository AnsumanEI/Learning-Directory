#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    cout << __gcd(16, 18); // in built funciton in cpp
    return 0;
}