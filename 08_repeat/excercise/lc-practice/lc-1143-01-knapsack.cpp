#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(string &text1, string &text2, vector<vector<int>> &memo, int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        if (text1[i] == text2[j])
        {
            memo[i][j] = 1 + helper(text1, text2, memo, i - 1, j - 1);
        }
        else
        {
            memo[i][j] = max(helper(text1, text2, memo, i - 1, j), helper(text1, text2, memo, i, j - 1));
        }
        return memo[i][j];
    }
    int tabulation(string &text1, string &text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return helper(text1, text2, memo, m - 1, n - 1);
    }
};
int main()
{

    return 0;
}