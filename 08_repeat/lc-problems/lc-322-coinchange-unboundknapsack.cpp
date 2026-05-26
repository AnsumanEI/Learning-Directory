#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solver(vector<int> &coins, vector<vector<int>> &memo, int amount)
    {
        int best = INT_MAX;
        if (amount == 0)
        {
            return 0;
        }

        for (auto &p : coins)
        {
            if (p <= amount)
            {
                int rem = solver(coins, memo, amount - p);
                if (rem != INT_MAX)
                {
                    best = min(best, 1 + rem);
                }
            }
        }
        return best;
    }
    int coinChange(vector<int> &coins, int amount)
    {
    }
};
int main()
{

    return 0;
}