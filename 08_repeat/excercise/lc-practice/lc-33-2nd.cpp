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
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target <= nums[mid])
                {
                    r = mid - 1;
                }

                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (target >= nums[mid] && target <= nums[r])
                {
                    l = mid + 1;
                }

                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
int main()
{

    return 0;
}