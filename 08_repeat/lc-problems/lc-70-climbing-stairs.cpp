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
    int memory(int n, int prev1, int prev2)
    {
        int current = 0;
        for (int i = 3; i <= n; i++)
        {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return memory(n, 2, 1);
    }
};
int main()
{
    Solution obj;

    cout << obj.climbStairs(3) << endl;
    return 0;
}