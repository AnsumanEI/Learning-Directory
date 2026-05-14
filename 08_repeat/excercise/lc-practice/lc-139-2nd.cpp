#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solver(unordered_set<string> &dict, string &s, int ind, vector<int> &memo)
    {
        if (ind == s.size())
        {
            return true;
        }
        if (memo[ind] != -1)
        {
            return memo[ind];
        }
        for (int i = ind; i <= s.size(); i++)
        {
            string cat = s.substr(ind, i - ind);

            if (dict.count(cat))
            {
                if (solver(dict, s, i, memo))
                {
                    memo[ind] = true;
                    return true;
                }
            }
        }
        memo[ind] = false;
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size() + 1, -1);
        return solver(dict, s, 0, memo);
    }
};
int main()
{
    return 0;
}