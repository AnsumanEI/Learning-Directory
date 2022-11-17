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
    vector<int> prime(n + 1, 1);
    prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!prime[i])
            continue;
        for (int j = i * i; j <= n; j += i) // for more fast we can also use i*i but as i cant think on that level so we will use 2*i
        {
            prime[j] = 0;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        cout << i << " ";
        if (prime[i])
            cout << "prime" << endl;
        else
        {
            cout << "not prime" << endl;
        }
    }
    return 0;
}