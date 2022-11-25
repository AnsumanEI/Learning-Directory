#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void printpermutation(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
}
class Solution
{
public:
    void help(vector<int> &nums, int target, vector<int> &ds, int freq[], vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (target >= nums[i] && !freq[i])
            {
                ds.push_back(i);
                freq[i] = 1;
                help(nums, target - nums[i], ds, freq, ans);
                continue;
            }
        }
    }

    vector<vector<int>> twoSum(vector<int> &nums, int target)
    {
        vector<int> ds;
        vector<vector<int>> ans;
        int freq[nums.size()] = {0};
        help(nums, target, ds, freq, ans);
        return ans;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<vector<int>> ans = obj.twoSum(nums, target);
    printpermutation(ans);

    return 0;
}