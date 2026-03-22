#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int isBadVersion(int n); // defined in the api in leetcode
    int firstBadVersion(int n)
    {
        int l = 1;
        int r = n;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (isBadVersion(mid) == 1)
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return l;
    }
};
int main()
{
    Solution a;
    a.firstBadVersion(10);
    return 0;
}