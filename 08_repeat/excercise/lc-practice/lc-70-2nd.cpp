#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int topdown(vector<int> &memo, int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        if (memo[n] != -1)
        {
            return memo[n];
        }
        memo[n] = topdown(memo, n - 1) + topdown(memo, n - 2);
        return memo[n];
    }
    int bottomup(int n)
    {

        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int spaceoptimised(int n)
    {
        int prev = 1;
        int curr = 2;
        for (int i = 3; i <= n; i++)
        {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
    int climbStairs(int n)
    {
        vector<int> memo(n + 1, -1);
        int tp = topdown(memo, n);
        int bp = bottomup(n);
        return bp;
    }
};
int main()
{
    return 0;
}