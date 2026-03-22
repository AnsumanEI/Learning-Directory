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
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) // not optimised as it run in a greater time complexity o(n)
        {
            count++;
        }
    }
    cout << endl;
    if (count == 2)
    {
        cout << "prime" << endl;
    }
    else
    {
        cout << "not prime" << endl;
    }
    return 0;
}