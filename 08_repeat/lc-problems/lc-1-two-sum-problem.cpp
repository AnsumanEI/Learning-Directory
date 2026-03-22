/*
 * #1 Two Sum
 *
 * APPROACH : Hash Map (Single Pass)
 *   - Compute complement = target - nums[i] for each element
 *   - If complement exists in map → return {map[complement], i}
 *   - Else store nums[i] → i in map and continue
 *
 * COMPLEXITY :
 *   Time  : O(n) - single pass, O(1) avg lookup with unordered_map
 *   Space : O(n) - unordered_map stores at most n elements
 *             unordered_map<int,int> map → O(n)
 *             int complement             → O(1)
 *
 * ALTERNATIVES :
 *   1. Brute Force         - O(n²)      / O(1)
 *   2. Sort + Two Pointers - O(n log n) / O(n)
 *   3. Hash Map (this)     - O(n)       / O(n)
 *
 * NOTE :
 *   unordered_map → hash table → O(1) avg lookup → O(n) overall
 *   std::map      → sorted BST → O(log n) lookup → O(n log n) overall
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.find(complement) != map.end())
            {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}