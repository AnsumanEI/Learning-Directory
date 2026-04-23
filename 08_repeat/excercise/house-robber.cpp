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
    int topdown(vector<int> &nums, vector<int> &memo, int i)
    {
        if (i == 0)
            return nums[i];
        if (i == 1)
            return max(nums[0], nums[1]);

        if (memo[i] != -1)
            return memo[i];

        memo[i] = max(topdown(nums, memo, i - 2) + nums[i], topdown(nums, memo, i - 1));
        return memo[i];
    }
    int bottomup(vector<int> &nums, vector<int> &dp, int n)
    {
        dp[0] = nums[0];

        if (n == 0)
            return dp[0];
        if (n == 1)
        {
            {
                dp[1] = max(nums[0], nums[1]);
                return dp[1];
            }
        }
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n + 1, -1);
        vector<int> dp(n + 1, 0);

        return bottomup(nums, dp, n - 1);
    }
};
int main()
{

    return 0;
}