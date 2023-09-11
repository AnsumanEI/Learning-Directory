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
    int pivot(vector<int> &num)
    {
        int l = 0;
        int n = num.size();
        int r = n - 1;
        int mid = l + (r - l) / 2;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (num[mid] == 0)
                return mid;
            else if (num[mid] > num[n])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    int binarysearch(vector<int> &num, int l, int r, int target)
    {
        int mid = l + (r - l) / 2;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (num[mid] == target)
            {
                return mid;
            }
            else if (num[mid] > target)
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return -1;
    }

public:
    int search(vector<int> &nums, int target)
    {
        int pv = pivot(nums);
        int ans = binarysearch(nums, 0, pv - 1, target);
        if (ans == -1)
            ans = binarysearch(nums, pv, nums.size() - 1, target);
        return ans;
    }
};
int main()
{
    vector<int> nums = {3, 1};
    Solution one;
    cout << one.search(nums, 1);
    return 0;
}