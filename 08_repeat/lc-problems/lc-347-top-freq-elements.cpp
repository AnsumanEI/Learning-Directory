/*
 * #347 Top K Frequent Elements
 *
 * APPROACH : HashMap Count + Sort Pairs
 *   - freq[val]++ builds frequency map
 *   - res collects {frequency, number} pairs from map
 *   - sort(rbegin(),rend()) sorts highest freq first
 *   - First k pairs → result numbers
 *
 * COMPLEXITY :
 *   Time  : O(n + d log d)  n=nums.size(), d=distinct
 *   Space : O(n)
 *
 * READABLE VARIABLES :
 *   nums     → input array
 *   freq     → frequency_map
 *   val      → current_number
 *   res/ap   → freq_pairs / map_entry
 *   ppsh     → result_numbers
 *
 * EDGE CASES :
 *   - k=1: single most frequent ✓
 *   - All unique: first k arbitrary ✓
 *   - k=nums.size(): all elements ✓
 */

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
    // Brute force
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto &val : nums)
        {
            freq[val]++;
        }
        vector<pair<int, int>> res;
        for (auto &ap : freq)
        {
            res.push_back({ap.second, ap.first});
        }
        sort(res.rbegin(), res.rend());
        vector<int> ppsh;
        for (int i = 0; i < k; i++)
        {
            ppsh.push_back(res[i].second);
        }
        return ppsh;
    }

    // Using min Heap

    vector<int> topKFrequent_using_minheap(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto &pr : nums)
        {
            freq[pr] += 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minpq;

        for (auto &pd : freq)
        {
            minpq.push({pd.second, pd.first});
            if (minpq.size() > k)
            {
                minpq.pop();
            }
        }

        vector<int> res;

        while (!minpq.empty())
        {
            res.push_back(minpq.top().second);
            minpq.pop();
        }

        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k = 2;
    vector<int> res = obj.topKFrequent(nums, k);
    for (auto &pr : res)
    {
        cout << pr << " ";
    }
    return 0;
}