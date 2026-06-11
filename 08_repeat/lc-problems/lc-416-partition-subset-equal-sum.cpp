#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool helper(vector<int> &nums, vector<vector<int>> &memo, int target, int index)
    {
        if (target == 0)
        {
            return true;
        }
        if (memo[index][target] != -1)
        {
            return memo[index][target];
        }
        for (int i = index; i < nums.size(); i++)
        {

            if (nums[i] <= target)
            {
                if (helper(nums, memo, target - nums[i], i + 1))
                {
                    return memo[index][target] = true;
                }
            }
        }
        return memo[index][target] = false;
    }
    bool canPartition(vector<int> &nums)
    {
        int totalsum = 0;
        for (auto &p : nums)
        {
            totalsum += p;
        }

        if (totalsum % 2 == 0)
        {
            vector<vector<int>> memo(nums.size() + 1, vector<int>(totalsum / 2 + 1, -1));
            return helper(nums, memo, totalsum / 2, 0);
        }
        return false;
    }
};
int main()
{

    return 0;
}