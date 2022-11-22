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
class solution
{
private:
    void findpermutation(vector<vector<int>> &ans, vector<int> &ds, int freq[], vector<int> &num)
    {
        if (ds.size() == num.size())
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < num.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(num[i]);
                freq[i] = 1;
                findpermutation(ans, ds, freq, num);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> perm(vector<int> &num)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[num.size()] = {0};
        findpermutation(ans, ds, freq, num);
        return ans;
    }
};
int main()
{
    vector<int> num = {1, 2, 3};
    solution obj;
    vector<vector<int>> ans = obj.perm(num);
    printpermutation(ans);

    return 0;
}