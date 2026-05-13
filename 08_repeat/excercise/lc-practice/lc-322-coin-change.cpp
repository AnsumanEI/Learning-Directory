#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp(vector<int> &coins, vector<int> &memo, int amt)
    {
        int bestcount = INT_MAX;

        if (amt == 0)
        {
            return 0;
        }
        if (memo[amt] != -1)
        {
            return memo[amt];
        }

        for (auto &p : coins)
        {
            if (p <= amt)
            {
                int count = 1 + dp(coins, memo, amt - p);
                if (count != INT_MAX)
                {
                    bestcount = min(count, bestcount);
                }
            }
        }
        memo[amt] = bestcount;
        return memo[amt];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> memo(amount + 1, -1);
        int res = dp(coins, memo, amount);
        if (res == INT_MAX)
        {
            return -1;
        }
        return res;
    }
};
int main()
{

    return 0;
}