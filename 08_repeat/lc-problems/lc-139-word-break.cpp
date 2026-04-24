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
    bool topdown(string &s, unordered_set<string> &word, int i, vector<int> &memo)
    {
        if (i == s.size())
        {
            memo[i] = true;
            return true;
        }
        if (memo[i] != -1)
            return memo[i];
        for (int j = i; j < s.size(); j++)
        {
            string wstr = s.substr(i, j - i + 1);
            if (word.count(wstr))
            {
                if (topdown(s, word, j + 1, memo))
                {
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false;
    }
    bool solvebottomup(string &s, unordered_set<string> &word, int i, vector<int> &memo)
    {
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> memo(s.size() + 1, -1);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        bool bumup = solvebottomup(s, dict, s.size() - 1, memo);
        return topdown(s, dict, 0, memo);
    }
};
int main()
{

    return 0;
}