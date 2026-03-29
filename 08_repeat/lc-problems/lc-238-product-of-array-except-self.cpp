/*
 * ============================================================
 *  LeetCode #238 — Product of Array Except Self
 * ============================================================
 *
 *  PROBLEM:
 *  Given an array nums, return an array answer such that:
 *      answer[i] = product of all elements except nums[i]
 *
 *  CONSTRAINT:
 *  - Do NOT use division
 *  - Must run in O(n)
 *
 * ------------------------------------------------------------
 *  INTUITION (VERY IMPORTANT 🔑)
 *
 *  For each index i:
 *      answer[i] = (product of left side) * (product of right side)
 *
 *  Example:
 *      nums = [1, 2, 3, 4]
 *
 *      For index 2 (value = 3):
 *      left  = 1 * 2 = 2
 *      right = 4
 *      answer[2] = 2 * 4 = 8
 *
 * ------------------------------------------------------------
 *  APPROACH 1: Prefix + Suffix Arrays (Easy to Understand)
 *
 *  STEP 1:
 *      prefix[i] = product of all elements to the LEFT of i
 *
 *  STEP 2:
 *      suffix[i] = product of all elements to the RIGHT of i
 *
 *  STEP 3:
 *      result[i] = prefix[i] * suffix[i]
 *
 *  EXTRA SPACE: O(n)
 *
 * ------------------------------------------------------------
 *  APPROACH 2: Optimized (O(1) Space) ⭐
 *
 *  Key Idea:
 *      - Use result[] to store prefix
 *      - Use a variable "suffix" while traversing from right
 *
 *  PASS 1 (Left → Right):
 *      Store prefix in result[]
 *
 *  PASS 2 (Right → Left):
 *      Multiply suffix dynamically
 *
 *  EXTRA SPACE: O(1)
 *
 * ------------------------------------------------------------
 *  COMPLEXITY:
 *      Time  : O(n)
 *      Space : O(1) (optimized version)
 * ------------------------------------------------------------
 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf_BruteBetter(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> result(n);

        prefix[0] = 1;
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];

        for (int i = 0; i < n; i++)
            result[i] = prefix[i] * suffix[i];

        return result;
    }

    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> result(n);

        result[0] = 1;
        for (int i = 1; i < n; i++)
            result[i] = result[i - 1] * nums[i - 1];

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};