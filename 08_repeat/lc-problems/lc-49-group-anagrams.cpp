/*
 * #49 Group Anagrams
 *
 * APPROACH : Sorting + HashMap
 *   - val1 = sorted version of val (key)
 *   - counter[val1].push_back(val) groups anagrams
 *   - res collects all counter[...].second values
 *
 * COMPLEXITY :
 *   Time  : O(n*klogk) where n=strs.size(), k=avg word length
 *   Space : O(n*k)
 *
 * READABLE VARIABLES :
 *   strs     → input word list
 *   val      → original_word
 *   val1     → sorted_key
 *   counter  → anagram_groups
 *   res/gra  → result / group_pair
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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        map<string, vector<string>> counter;

        for (auto &val : strs)
        {
            string val1 = val;
            sort(val1.begin(), val1.end());

            counter[val1].push_back(val);
        }
        vector<vector<string>> res;
        for (auto &gra : counter)
        {
            res.push_back(gra.second);
        }
        return res;
    }
};
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res;

    Solution obj;

    res = obj.groupAnagrams(strs);

    for (auto &prin : res)
    {
        for (auto &pr2 : prin)
        {
            cout << pr2 << " ";
        }
        cout << endl;
    }
    return 0;
}