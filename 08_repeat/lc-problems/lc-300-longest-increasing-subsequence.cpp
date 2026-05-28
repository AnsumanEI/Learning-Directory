#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solver(int curr_ind, int prev_ind, vector<int> &nums,
               vector<vector<int>> &memo)
    {

        if (curr_ind == nums.size())
        {
            return 0;
        }
        if (memo[curr_ind][prev_ind + 1] != -1)
        {
            return memo[curr_ind][prev_ind + 1];
        }
        int exclude = solver(curr_ind + 1, prev_ind, nums, memo);
        int include = 0;
        if (prev_ind == -1 || nums[curr_ind] > nums[prev_ind])
        {
            include = 1 + solver(curr_ind + 1, curr_ind, nums, memo);
        }
        return memo[curr_ind][prev_ind + 1] = max(include, exclude);
    }
    int lengthOfLISrecursionmemo(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return solver(0, -1, nums, memo);
    }
    int lengthOfLIS1darray(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            int best = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] > best)
                    {
                        best = dp[j];
                    }
                }
            }
            dp[i] = best + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{

    return 0;
}