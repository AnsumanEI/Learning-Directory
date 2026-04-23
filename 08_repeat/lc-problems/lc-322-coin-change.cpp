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
    int topdown(vector<int> &coins, vector<int> &memo, int amt)
    {
        int best = INT_MAX;
        if (amt == 0)
            return 0;
        if (memo[amt] != -1)
            return memo[amt];

        for (int coin : coins)
        {
            if (coin <= amt)
            {
                int rem = topdown(coins, memo, amt - coin);
                if (rem != INT_MAX)
                {
                    best = min(best, 1 + rem);
                }
            }
        }
        memo[amt] = best;
        return best;
    }

    int bottomup(vector<int> &coins, vector<int> &dp, int amt)
    {
        dp[0] = 0;

        for (int i = 1; i <= amt; i++)
        {
            for (auto &coin : coins)
            {
                if (coin <= i && dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return dp[amt];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> memo(amount + 1, -1);
        int res2 = topdown(coins, memo, amount);
        vector<int> dp(amount + 1, INT_MAX);
        int res1 = bottomup(coins, dp, amount);

        if (res1 == INT_MAX)
            return -1;
        else
            return res1;
    }
};
int main()
{

    return 0;
}