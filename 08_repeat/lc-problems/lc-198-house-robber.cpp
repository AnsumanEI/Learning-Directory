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
    // memoisation after brute force recursion
    int memoisation(vector<int> &nums, int i, vector<int> &memo)
    {
        if (memo[i] != -1)
        {
            return memo[i];
        }
        if (i == 0)
        {
            return nums[0];
        }
        if (i == 1)
        {
            return max(nums[1], nums[0]);
        }

        memo[i] = max(nums[i] + memoisation(nums, i - 2, memo), memoisation(nums, i - 1, memo));
        return memo[i];
    }
    int dp(vector<int> &nums)
    {
        int current;
        int prev1 = max(nums[0], nums[1]);
        int prev2 = nums[0];

        if (nums.size() == 1)
            return nums[0];

        for (int i = 2; i < nums.size(); i++)
        {
            current = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    int rob(vector<int> &nums)

    {
        vector<int> memo(nums.size(), -1);
        int dpsol = dp(nums);
        int memovalue = memoisation(nums, nums.size() - 1, memo);
    }
};

int main()
{

    return 0;
}