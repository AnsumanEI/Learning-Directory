#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class solution
{
    void func(vector<int> &nums, int index, vector<int> &ds, vector<vector<int>> &ans, int freq[], int n)
    {
        if (index == n - 1)
        {
            if (ds.size() == 3)
            {
                ans.push_back(ds);
            }
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                nums[i] = 1;
                func(nums, i, ds, ans, freq, n);
                freq[i - 1] = 0;
                ds.pop_back();
            }
        }
    }

public:
    int counttriplets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()] = {0};
        func(nums, 0, ds, ans, freq, nums.size());
        return ans.size();
    }
};
int main()
{
    solution obj;
    vector<int> nums = {1, 2, 3};
    cout << "magic triplets are " << obj.counttriplets(nums);
    return 0;
}