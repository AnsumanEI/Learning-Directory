#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void printAns(vector<vector<int>> &ans)
{
    cout << "subsets are " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
        cout << endl;
    }
}
class solution
{
public:
    void combfinder(vector<vector<int>> &ans, vector<int> &ds, int target, vector<int> &nums, int index)
    {
        if (index == nums.size() || target == 0)
        {
            if (target == 0)
            {
                ans.push_back(ds);
                return;
            }
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            if (nums[i] <= target)
            {
                ds.push_back(nums[i]);
                combfinder(ans, ds, target - nums[i], nums, i + 1);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> helper(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        combfinder(ans, ds, target, nums, 0);
        return ans;
    }
};

int main()
{
    solution obj;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans = obj.helper(nums, 6);
    printAns(ans);
    return 0;
}