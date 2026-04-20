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
    int lcsrecursion(string &text1, string &text2, int i, int j, vector<vector<int>> &memo)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        else if (text1[i] == text2[j])
        {
            return memo[i][j] = 1 + lcsrecursion(text1, text2, i - 1, j - 1, memo);
        }
        else
        {
            return memo[i][j] = max(lcsrecursion(text1, text2, i - 1, j, memo), lcsrecursion(text1, text2, i, j - 1, memo));
        }
    }

    int lcstabulation(string &text1, string &text2, vector<vector<int>> &table)
    {
        int m = text1.size();
        int n = text2.size();
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    table[i][j] = 1 + table[i - 1][j - 1];
                }
                else
                {
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
                }
            }
        }
        return table[m][n];
    }

    int lcsprevcurr(string &text1, string &text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n + 1, 0);
        vector<int> cur(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    cur[j] = 1 + prev[j - 1];
                }
                else
                {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }
        return prev[n];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0)); // base case was 0 as we shifted right so i< 0 became i==0 and i = i-1  , so if i call n now it will be n-1

        int res2 = lcstabulation(text1, text2, table);

        int res1 = lcsrecursion(text1, text2, m - 1, n - 1, memo);
        return res1;
    }
};
int main()
{
    string text1 = "axyt";
    string text2 = "ayzx";
    Solution ibj;
    cout << ibj.longestCommonSubsequence(text1, text2);

    return 0;
}