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
    vector<int> twoSum(vector<int> &nums, int target)
    {

                int l = 0, r = nums.size() - 1;
        vector<int> ans = {};
        int mid = l + (r - l) / 2;
        while (l <= r && l + r != 0)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] <= target)
            {
                target -= nums[mid];
                r = mid;
                ans.push_back(mid);
            }
            else
            {
                l = mid + 1;
            }
        }
        if (target == 0)
        {
            return ans;
        }
        else
        {
            return {};
        }
    }
};
int main()
{
    Solution a;
    vector<int> grid = {3, 2, 4};
    int target = 9;
    vector<int> res = a.twoSum(grid, target);
    cout << res.at(1) << " " << res.at(0);
}