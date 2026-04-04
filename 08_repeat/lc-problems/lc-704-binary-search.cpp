/*
 * #704 Binary Search
 *
 * APPROACH : Classic lo/hi/mid template
 *   - lo=0, hi=n-1, mid=lo+(hi-lo)/2
 *   - If nums[mid]==target → return mid
 *   - If target > nums[mid] → search right half
 *   - If target < nums[mid] → search left half
 *
 * COMPLEXITY :
 *   Time  : O(log n)  dividing in half each time
 *   Space : O(1)
 *
 * READABLE VARIABLES :
 *   nums   → input array
 *   target → number to find
 *   low    → left boundary
 *   high   → right boundary
 *   mid    → middle index
 *
 * EDGE CASES :
 *   - Target not in array → return -1 ✓
 *   - Single element array ✓
 *   - Target at boundaries ✓
 *
 * NOTE :
 *   - Always use lo+(hi-lo)/2 NOT (lo+hi)/2 → overflow risk
 */

#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            if (target > nums[mid]) low = mid + 1;
            else if (target < nums[mid]) high = mid - 1;
        }
        return -1;
    }
};
return 0;
}