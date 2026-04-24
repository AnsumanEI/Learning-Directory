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
    void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> curr, vector<bool> &visited)
    {
        if (curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                curr.push_back(nums[i]);
                solve(nums, res, curr, visited);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> visited(nums.size() + 1, false);
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums, res, curr, visited);
        return res;
    }
};
int main()
{
    return 0;
}