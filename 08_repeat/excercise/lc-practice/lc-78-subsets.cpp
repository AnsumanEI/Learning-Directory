#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int ind)
{
    res.push_back(curr);
    for (int i = ind; i < nums.size(); i++)
    {
        curr.push_back(nums[i]);
        solve(nums, res, curr, i + 1);
        curr.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
}
int main()
{

    return 0;
}