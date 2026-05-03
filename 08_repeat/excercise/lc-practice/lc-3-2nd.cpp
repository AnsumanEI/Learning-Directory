#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxlen = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> store;
        while (r < s.size())
        {
            while (store.count(s[r]))
            {
                store.erase(s[l]);
                l++;
            }
            store.insert(s[r]);
            r++;

            maxlen = max(maxlen, (int)store.size());
        }
        return maxlen;
    }
};
int main()
{

    return 0;
}