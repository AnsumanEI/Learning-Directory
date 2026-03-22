#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 1000;
    vector<int> prime(n + 1, 1);
    prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!prime[i])
            continue;
        for (int j = 2 * i; j <= n; j += i)
        {
            prime[j] = 0;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (prime[i])
            cout << "prime" << endl;
        else
        {
            cout << "not prime" << endl;
        }
    }
    return 0;
}