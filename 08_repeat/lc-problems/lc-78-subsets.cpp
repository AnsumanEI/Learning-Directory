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
    void solve(vector<int> &sums, vector<int> curr, vector<vector<int>> &res, int ind)
    {
        res.push_back(curr);
        for (int i = ind; i < sums.size(); i++)
        {
            curr.push_back(sums[i]);
            solve(sums, curr, res, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> curr;
        vector<vector<int>> res;
        solve(nums, curr, res, 0);
        return res;
    }
};
int main()
{

    return 0;
}