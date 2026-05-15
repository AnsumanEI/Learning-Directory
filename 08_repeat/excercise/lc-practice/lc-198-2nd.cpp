#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solver(vector<int> &nums, vector<int> &memo, int i)
    {

        if (i == 0)
        {
            return nums[0];
        }
        if (i == 1)
        {
            return max(nums[0], nums[1]);
        }
        if (memo[i] != -1)
        {
            return memo[i];
        }
        memo[i] = max(solver(nums, memo, i - 2) + nums[i], solver(nums, memo, i - 1));
        return memo[i];
    }

    int tabulation(vector<int> &nums, vector<int> &dp)
    {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
    int rob(vector<int> &nums)
    {
        vector<int> memo(nums.size() + 1, -1);
        return solver(nums, memo, nums.size() - 1);
    }
};
int main()
{

    return 0;
}