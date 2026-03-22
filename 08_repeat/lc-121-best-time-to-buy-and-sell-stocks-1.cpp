/*
 * #121 Best Time to Buy and Sell Stock
 *
 * APPROACH : Single Pass (Min Tracking + Max Reset)
 *   - Track running min price seen so far
 *   - On new min, reset max to 0 (fresh window starts)
 *   - Track running max price seen so far
 *   - Update best profit inside loop after each step
 *
 * COMPLEXITY :
 *   Time  : O(n) - single pass through prices array
 *   Space : O(1) - only scalar variables used
 *             int min    → O(1)
 *             int max    → O(1)
 *             int size   → O(1)
 *             int profit → O(1)
 *
 * ALTERNATIVES :
 *   1. Brute Force         - O(n²) / O(1) - check every buy/sell pair
 *   2. Single Pass (this)  - O(n)  / O(1) - track min and best profit
 *
 * WRONG APPROACHES (edge cases) :
 *   1. else-if for min check  → skips min reset when prices[i] > max
 *      fails : [2, 1, 4] → misses reset, wrong profit
 *   2. profit computed outside loop → initialized as 0 - INT_MAX (garbage)
 *      fails : [2, 4, 1, 7] → best window never captured correctly
 *
 * NOTE :
 *   max must reset to 0 on new min — ensures we never sell before we buy
 *   profit update must live inside loop — captures best window dynamically
 */

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max = 0;
        int min = INT_MAX;
        int size = prices.size();
        int profit = max - min;
        for (int i = 0; i < size; i++)
        {
            if (prices[i] > max)
            {
                max = prices[i];
            }
            if (prices[i] < min)
            {
                min = prices[i];
                max = 0;
            }
            if (max - min > profit)
            {
                profit = max - min;
            }
        }

        return profit > 0 ? profit : 0;
    }
};
int main()
{
    vector<int> prices = {2, 4, 3, 1, 8, 2, 5, 6};
    Solution obj1;
    cout << obj1.maxProfit(prices);
    return 0;
}