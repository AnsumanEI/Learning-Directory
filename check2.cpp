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
    int lower_bound(vector<int> &nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int startingPosition = lower_bound(nums, low, high, target);
        int endingPosition = lower_bound(nums, low, high, target + 1) - 1;
        if (startingPosition < nums.size() && nums[startingPosition] == target)
        {
            return {startingPosition, endingPosition};
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