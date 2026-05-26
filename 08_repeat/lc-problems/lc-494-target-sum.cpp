#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solver(int index, int curr, int target, vector<int> &nums,
               vector<vector<int>> &memo, int totalsum)
    {
        if (index < 0)
        {
            if (curr == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int shiftcurr = curr + totalsum; // to accomodate for the negative number like -10 + 10 will be 0 and will go till 10 + 10 is 20 that is why we used the column size 2*totalsum +1
        if (memo[index][shiftcurr] != -1)
        {
            return memo[index][shiftcurr];
        } // so we will use curr only but to store we will use shift curr

        int plus = solver(index - 1, curr + nums[index], target, nums, memo, totalsum);
        int minus = solver(index - 1, curr - nums[index], target, nums, memo, totalsum);

        return memo[index][shiftcurr] = plus + minus;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalsum = 0;
        for (auto &p : nums)
        {
            totalsum += p;
        }
        if (target > totalsum)
        {
            return 0;
        }
        int totalcol = 2 * totalsum + 1;
        vector<vector<int>> memo(nums.size(), vector<int>(totalcol + 1, -1));
        return solver(nums.size() - 1, 0, target, nums, memo, totalsum);
    }
};
int main()
{

    return 0;
}