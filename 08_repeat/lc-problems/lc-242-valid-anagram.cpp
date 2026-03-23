#include <bits/stdc++.h>
using namespace std;

/*
 * #242 Valid Anagram
 *
 * APPROACH 1 : Two Hash Maps (Frequency Compare)
 *   - Count frequency of characters in both strings
 *   - Compare both maps directly
 *
 * APPROACH 2 : Single Hash Map (Optimized)
 *   - Increment for s, decrement for t
 *   - Final map should have all values = 0
 *
 * COMPLEXITY :
 *   Time  : O(n)
 *   Space : O(1) - at most 26 characters
 *
 * ALTERNATIVES :
 *   1. Sorting - O(n log n)
 *
 * NOTE :
 *   Always check size first to avoid unnecessary work
 */

class Solution
{
public:
    // ------------------ APPROACH 1 ------------------
    bool isAnagram_MapCompare(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> freqs;
        unordered_map<char, int> freqt;

        for (auto &c : s)
        {
            freqs[c]++;
        }

        for (auto &c : t)
        {
            freqt[c]++;
        }

        return freqs == freqt;
    }

    // ------------------ APPROACH 2 ------------------
    bool isAnagram_OneMap(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> freq;

        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for (auto &p : freq)
        {
            if (p.second != 0)
                return false; // FIXED
        }

        return true;
    }
};

int main()
{
    Solution obj;

    string s = "anagram";
    string t = "nagaram";

    cout << "Approach 1 (Map Compare): ";
    cout << (obj.isAnagram_MapCompare(s, t) ? "Valid" : "Invalid") << endl;

    cout << "Approach 2 (One Map): ";
    cout << (obj.isAnagram_OneMap(s, t) ? "Valid" : "Invalid") << endl;

    return 0;
}