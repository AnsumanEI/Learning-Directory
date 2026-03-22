#include <bits/stdc++.h>
using namespace std;

int main()

{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;

        vector<long long int> v;
        for (long long int i = 0; i < n; i++)
        {
            long long int x;
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        long long int sum = 0;
        long long int i = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] <= i + 1)
            {
                sum += (i + 1) + v[i];
            }
            else
            {
                break;
            }
        }

        if (i != n)
        {
            cout << "Second" << endl;
        }
        else if (sum % 2 == 0)
        {
            cout << "Second" << endl;
        }
        else
        {
            cout << "First" << endl;
        }
    }
}
