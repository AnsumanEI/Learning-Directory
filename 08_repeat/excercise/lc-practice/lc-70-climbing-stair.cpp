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
    int topdown(vector<int> &memo, int i)
    {
        if (i == 1)
            return 1;
        if (i == 2)
            return 2;
        else if (memo[i] != -1)
            return memo[i];

        memo[i] = topdown(memo, i - 1) + topdown(memo, i - 2);
        return memo[i];
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
    int climbStairs(int n)
    {
        vector<int> memo(n + 1, -1);
        int res2 = bottomup(n);
        return topdown(memo, n);
    }
};
int main()
{

    return 0;
}