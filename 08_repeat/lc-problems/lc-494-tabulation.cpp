#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int totalsum = 0;
        for (auto &p : nums)
        {
            totalsum += p;
        }
        if (target > totalsum)
            return 0;
        int totalcol = 2 * totalsum + 1;

        vector<vector<int>> dp(n, vector<int>(totalcol, 0));
        dp[0][+nums[0] + totalsum] += 1;
        dp[0][-nums[0] + totalsum] += 1; // technically it should have been one but as if nums[0] = 0 then both the choices will point to a single place

        for (int i = 1; i < n; i++)
        {
            for (int curr = -totalsum; curr <= totalsum; curr++)
            {
                int shiftcurr = curr + totalsum;
                if (dp[i - 1][shiftcurr] > 0)
                {
                    int plus = curr + nums[i];
                    dp[i][plus + totalsum] += dp[i - 1][shiftcurr];

                    int minus = curr - nums[i];
                    dp[i][minus + totalsum] += dp[i - 1][shiftcurr];
                }
            }
        }
        return dp[n - 1][target + totalsum];
    }
};
int main()
{

    return 0;
}