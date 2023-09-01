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
    long long mySqrt(int x)
    {
        long long l = 1;
        long long r = x;
        long long mid = l + (r - l) / 2;
        if (x <= 1)
            return x;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l - 1;
    }
};
int main()
{
    Solution a;
    cout << a.mySqrt(8);
}