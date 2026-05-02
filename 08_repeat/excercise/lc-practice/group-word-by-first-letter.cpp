#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    vector<string> nums = {"apple", "ant", "banana", "avocado", "berry"};
    unordered_map<char, vector<string>> counter;

    for (auto &p : nums)
    {
        char val = p[0];
        counter[val].push_back(p);
    }
    for (auto &pr : counter)
    {
        cout << pr.first << ": ";
        for (auto &res : pr.second)
        {
            cout << res << "  ";
        }
        cout << endl;
    }
    return 0;
}