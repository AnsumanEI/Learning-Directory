#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void printAns(vector<vector<int>> &ans)
{
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
    void getperm(int index, vector<vector<int>> &ans, vector<int> &nums)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            getperm(index + 1, ans, nums);
            swap(nums[i], nums[index]);
                }
    }
    vector<vector<int>> help(vector<int> &nums)
    {
        vector<vector<int>> ans;
        getperm(0, ans, nums);
        return ans;
    }
};
int main()
{
    solution obj;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = obj.help(nums);
    printAns(ans);
    return 0;
}