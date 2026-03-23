/*
 *#217 Contains Duplicate
 *
 * APPROACH : Hashing (Using Unordered Map)
 *   - Traverse through the array
 *   - Store elements in a hashmap
 *   - If element already exists → duplicate found
 *
 * COMPLEXITY :
 *   Time  : O(n) - single pass through array
 *   Space : O(n) - hashmap stores elements
 *             unordered_map<int,int> values → O(n)
 *
 * ALTERNATIVES :
 *   1. Sorting            - O(n log n) / O(1)
 *      → sort array and check adjacent elements
 *   2. HashSet (better)   - O(n) / O(n)
 *      → use unordered_set instead of map
 *
 * WRONG APPROACHES :
 *   1. Nested loops       → O(n²), inefficient
 *   2. Using map but not checking before inserting
 *
 * NOTE :
 *   unordered_set is preferred since we only care about presence,
 *   not frequency
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> values;

        for (auto &keys : nums)
        {
            if (values.find(keys) != values.end())
            {
                return true;
            }
            values[keys]++;
        }

        return false;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 1};

    if (obj.containsDuplicate(nums))
    {
        cout << "Duplicate exists" << endl;
    }
    else
    {
        cout << "No duplicate" << endl;
    }

    return 0;
}