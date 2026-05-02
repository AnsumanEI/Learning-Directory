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
    int topdown(string &w1, string &w2, int i, int j, vector<vector<int>> &memo)
    {

        if (i < 0)
        {
            return j + 1;
        }
        if (j < 0)
        {
            return i + 1;
        }
        if (memo[i][j] != -1)
            return memo[i][j];
        if (w1[i] == w2[j])
        {
            memo[i][j] = topdown(w1, w2, i - 1, j - 1, memo);
        }
        else
        {
            memo[i][j] = 1 + min({topdown(w1, w2, i - 1, j - 1, memo), topdown(w1, w2, i, j - 1, memo), topdown(w1, w2, i - 1, j, memo)});
        }
        return memo[i][j];
    }

    int bottomup(string &w1, string &w2)
    {

        int m = w1.size();
        int n = w2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (w1[i - 1] == w2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        if (word1.size() == 0)
            return word2.size();
        if (word2.size() == 0)
            return word1.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int res1 = topdown(word1, word2, m - 1, n - 1, memo);
        return res1;
    }
};
int main()
{

    return 0;
}