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
    bool topbottom(string s, unordered_set<string> &dict, vector<int> &memo, int i)
    {
        if (i == s.size())
        {
            return true;
        }
        if (memo[i] != -1)
            return memo[i];

        for (int j = i; j <= s.size(); j++)
        {
            string cat = s.substr(i, j - i);

            if (dict.count(cat))
            {
                if (topbottom(s, dict, memo, j))
                {
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false;
    }

    bool bottomup(vector<int> &dp, unordered_set<string> &dict, int n, string s)
    {
        dp[0] = true;

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[j] == true && dict.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                }
            }
        }
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<int> memo(n + 1, -1);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        bool tb = topbottom(s, dict, memo, 0);
        vector<int> dp(s.size() + 1, 0);

        bool bt = bottomup(dp, dict, n, s);
        return tb; // bt ;
    }
};
int main()
{

    return 0;
}