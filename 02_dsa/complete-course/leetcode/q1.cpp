#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void print(vector<vector<int>> &ans)
{
    cout << "The unique subsets are " << endl;
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
private:
    void subsetsum(int index, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums)
    {
        ans.push_back(ds);
        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i - 1])

                continue;

            ds.push_back(nums[i]);
            subsetsum(i + 1, ans, ds, nums);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> findcombination(vector<int> &num)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(num.begin(), num.end());
        subsetsum(0, ans, ds, num);
        return ans;
    }
};
int main()
{
    solution obj;
    vector<int> num = {1, 2, 2, 3, 3};
    vector<vector<int>> ans1 = obj.findcombination(num);
    print(ans1);
    return 0;
}