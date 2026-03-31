/*
 * ============================================================
 *  LeetCode #239 — Sliding Window Maximum
 * ============================================================
 *
 *  PROBLEM:
 *  Given an array nums and a sliding window of size k,
 *  return the maximum value in each window position.
 *
 * ------------------------------------------------------------
 *  INTUITION (VERY IMPORTANT 🔑)
 *
 *  We need the max of every window of size k efficiently.
 *  A brute force scan of each window is O(n*k) — too slow.
 *
 *  Key Insight:
 *      Use a Monotonic Decreasing Deque that stores indices.
 *      The front always holds the index of the current max.
 *
 * ------------------------------------------------------------
 *  APPROACH: Monotonic Deque
 *
 *  RULE 1 (Maintain Decreasing Order):
 *      Before adding index r, pop from back while
 *      nums[back] < nums[r] — those values are useless.
 *
 *  RULE 2 (Remove Out-of-Window Elements):
 *      If front index < l (left boundary), pop from front.
 *
 *  RULE 3 (Collect Result):
 *      Once r >= k-1, window is full → push nums[front].
 *
 * ------------------------------------------------------------
 *  COMPLEXITY:
 *      Time  : O(n)
 *      Space : O(k)
 * ------------------------------------------------------------
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0; 
        int r = 0;
        deque<int> win;
        vector<int> res;
        while (r < nums.size()) {

            // check rule 1
            while (!win.empty() && nums[win.back()] < nums[r]) {
                win.pop_back();
            }
            win.push_back(r);

            // check rule 2 (old)
            if (win.front() < l) {
                win.pop_front();
            }
            if (r >= (k - 1)) {
                l++;
                res.push_back(nums[win.front()]);
            }
            r++;
        }
        return res;
    }
};
int main()
{
return 0;
}
