
/*
 * ============================================================
 *  LeetCode #3 — Longest Substring Without Repeating Characters
 * ============================================================
 *
 *  PROBLEM:
 *  Given a string s, return the length of the longest substring
 *  that contains no repeating characters.
 *
 * ------------------------------------------------------------
 *  INTUITION (VERY IMPORTANT 🔑)
 *
 *  Use a sliding window [l, r] and a set to track characters.
 *
 *  Expand r when s[r] is not in the window.
 *  Shrink l when s[r] already exists (duplicate found).
 *
 *  Example:
 *      s = "abcabcbb"
 *      Window expands to "abc", then hits 'a' again
 *      → shrink from left until 'a' is removed
 *      → window slides forward
 *
 * ------------------------------------------------------------
 *  APPROACH: Sliding Window + HashSet
 *
 *  STEP 1:
 *      If s[r] not in seen → insert, update maxLength, move r
 *
 *  STEP 2:
 *      If s[r] in seen → erase s[l], move l
 *
 * ------------------------------------------------------------
 *  COMPLEXITY:
 *      Time  : O(n)
 *      Space : O(n)
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
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_set<char> seen;
        int maxLength = 0;
        while (r < s.size()) {
            if (!seen.count(s[r])) {
                seen.insert(s[r]);
                if (seen.size() > maxLength) maxLength = seen.size();
                r++;
            }
            else if (seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
        }
        return maxLength;
    }
};
int main()
{


return 0;
}