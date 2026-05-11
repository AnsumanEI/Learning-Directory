#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int topdown(string text1, string text2, int i, int j, vector<vector<int>> &memo)
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
            memo[i][j] = 1 + topdown(text1, text2, i - 1, j - 1, memo);
        }
        else
        {
            memo[i][j] = max(topdown(text1, text2, i, j - 1, memo), topdown(text1, text2, i - 1, j, memo));
        }
        return memo[i][j];
    }

    int bottomup(string text1, string text2) // same order as topdown
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return dp[m][n];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int res1 = bottomup(text2, text1);
        int res2 = topdown(text1, text2, m - 1, n - 1, memo);
        return res1;
    }
};
int main()
{
    return 0;
}