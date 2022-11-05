#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> div(n);
    // what it does is that it counts the multiples of every number so at last when we add all the number of divisors are found
    // and iterations are not wasted
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            div[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << div[i] << endl;
    }
    return 0;
}