#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void printf1(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
}
class solution
{
private:
    void subset(vector<vector<int>> &ans, vector<int> &ds, vector<int> &num, int index)
    {
        ans.push_back(ds);
        for (int i = index; i < num.size(); i++)
        {
            if (i != index && num[i] == num[i - 1])
                continue;
            ds.push_back(num[i]);
            subset(ans, ds, num, i + 1);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> helper(vector<int> &num)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(num.begin(), num.end());
        subset(ans, ds, num, 0);
        return ans;
    }
};
int main()
{
    solution obj;
    vector<int> num = {1, 2, 2, 3};
    vector<vector<int>> ans1 = obj.helper(num);
    printf1(ans1);
    return 0;
}