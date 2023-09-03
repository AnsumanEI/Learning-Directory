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
    int arrangeCoins(int n)
    {
        int l = 1;
        int r = n;
        int mid = l + (r - l) / 2;
        int total = mid * (mid + 1) / 2;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            total = mid * (mid + 1) / 2;
            if (n == 0 || n == 1)
            {
                return n;
            }
            if (total <= n)
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return mid;
    }
};
int main()
{
    Solution a;
    cout << a.arrangeCoins(8);
    return 0;
}