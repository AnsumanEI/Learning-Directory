#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int func(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + func(n - 1);
}
int main()
{
    cout << func(10) << endl;
    return 0;
}