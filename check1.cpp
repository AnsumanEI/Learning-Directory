#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class Solution
{
private:
    int find_low(vector<int> &nums, int target, int left, int right)
    {
        while (left <= right)
        {
            int mid = (left + right) >> 1; // it means dividing by two as >>1 = 2^1 =2
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int start = find_low(nums, target, l, r);
        int end = find_low(nums, target + 1, l, r) - 1; // as this will give the postion of the number just immediate next to it
        if (start < nums.size() && nums[start] == target)
        {
            return {start, end};
        }
        return {-1, -1};
    }
};
int main()
{
    Solution a;
    vector<int> nums = {1, 1, 2, 2, 3};
    vector<int> ans = a.searchRange(nums, 2);
    cout << ans.at(0) << ans.at(1) << endl;
    return 0;
}