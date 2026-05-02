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
        int l = 0;
        int r = 0;
        unordered_set<char> seen;
        int maxLen = 0;

        while (r < s.size()) // here i wrote r!=s.size
        {
            while (seen.count(s[r])) // i was trying if loop if inside then while
            {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            r++;

            maxLen = max(maxLen, (int)seen.size());
        }
        return maxLen;
    }
};
int main()
{

    return 0;
}