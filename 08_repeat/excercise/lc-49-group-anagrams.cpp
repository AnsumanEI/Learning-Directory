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
        unordered_map<string, vector<string>> store;

        for (auto &p : strs)
        {
            string curr = p;
            sort(curr.begin(), curr.end());

            store[curr].push_back(p);
        }
        vector<vector<string>> res;
        for (auto &p : store)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
int main()
{

    return 0;
}