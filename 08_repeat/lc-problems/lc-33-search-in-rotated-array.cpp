/*
 * #33 Search in Rotated Sorted Array
 *
 * APPROACH : Binary Search with half-identification
 *   - One half is always normally sorted after rotation
 *   - nums[mid] >= nums[l] → left half is sorted
 *   - Check if target falls in sorted half using >= and <=
 *   - Otherwise search the other half
 *
 * COMPLEXITY :
 *   Time  : O(log n)
 *   Space : O(1)
 *
 * READABLE VARIABLES :
 *   nums   → input rotated array
 *   target → number to find
 *   l      → left boundary
 *   h      → right boundary
 *   mid    → middle index
 *
 * EDGE CASES :
 *   - Use >= not > when comparing nums[mid] to nums[l]
 *     (when l==mid, > breaks the condition)
 *   - Use >= nums[l] and <= nums[h] in range checks
 *     (target could equal boundary elements)
 *   - Target not present → return -1 ✓
 */
#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (target == nums[mid])
                return mid;
            if (nums[mid] >= nums[l]) {
                if (target < nums[mid] && target >= nums[l])
                    h = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{


return 0;
}