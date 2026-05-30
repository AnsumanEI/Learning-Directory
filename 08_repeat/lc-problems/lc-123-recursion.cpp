#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solver(int index, int flag, int trans, vector<int> &prices, vector<vector<vector<int>>> &memo)
    {
        if (index == prices.size() || trans == 0)
        {
            return 0;
        }
        if (memo[index][flag][trans] != -1)
        {
            return memo[index][flag][trans];
        }
        if (flag == 1) // buy
        {
            int buy = -prices[index] + solver(index + 1, 0, trans, prices, memo);
            int skip = 0 + solver(index + 1, 1, trans, prices, memo);
            return memo[index][flag][trans] = max(buy, skip);
        }
        else // sell
        {
            int sell = prices[index] + solver(index + 1, 1, trans - 1, prices, memo);
            int skip = 0 + solver(index + 1, 0, trans, prices, memo);
            return memo[index][flag][trans] = max(sell, skip);
        }
    }
    int tabulation(vector<vector<vector<int>>> &dp, vector<int> &prices)
    {
        int n = prices.size();

        for (int index = n - 1; index >= 0; index--)
        {
            for (int flag = 0; flag <= 1; flag++)
            {
                for (int trans = 1; trans <= 2; trans++)
                {
                    if (flag == 1) // buy
                    {
                        int buy = -prices[index] + dp[index + 1][0][trans];
                        int skip = 0 + dp[index + 1][1][trans];

                        dp[index][flag][trans] = max(buy, skip);
                    }
                    else // sell
                    {
                        int sell = prices[index] + dp[index + 1][1][trans - 1];
                        int skip = 0 + dp[index + 1][0][trans];

                        dp[index][flag][trans] = max(sell, skip);
                    }
                }
            }
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        return solver(0, 1, 2, prices, memo);
    }
};
int main()
{

    return 0;
}