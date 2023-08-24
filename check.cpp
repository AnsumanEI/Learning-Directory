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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        vector<int> ans(2, -1);
        while (l <= r && r >= 0 && l >= 00)
        {
            int mid = l + (r - l) / 2;
            if (mid < 0 || mid > nums.size() - 1 || r < 0)
            {
                break;
            }
            if (nums[mid] == target)
            {

                if (nums[mid - 1] == target)
                {
                    ans[0] = mid - 1;
                }
                else if (nums[mid + 1] == target)
                {
                    ans[0] = mid + 1;
                }
                else
                {
                    ans[0] = mid;
                }
                ans[1] = mid;

                break;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution a;
    vector<int> grid = {1, 1, 1, 2, 2, 2, 3, 4, 5, 6, 7};
    int target = 2;
    vector<int> ans1 = a.searchRange(grid, target);
    cout << ans1.at(0) << ans1.at(1) << endl;
}