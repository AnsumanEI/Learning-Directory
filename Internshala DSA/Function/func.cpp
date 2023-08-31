#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
// int fact(int num)
// {
//     if (num == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return fact(num - 1) * num;
//     }
// }

int sum(int a, int b) // prototype
{
    return a + b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = sum(a, b); // calling or argument passing
    cout << ans << endl;
    // cout << fact(2);
    return 0;
}