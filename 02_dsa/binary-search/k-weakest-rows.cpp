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
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> rowStrengths;
        int n = mat.size();
        for (int i = 0; i < mat.size(); ++i)
        {
            int strength = accumulate(mat[i].begin(), mat[i].end(), 0);
            rowStrengths.push_back({strength, 1});
        }

        sort(rowStrengths.begin(), rowStrengths.end());

        vector<int> result;
        for (int i = 0; i < k; ++i)
        {
            result.push_back(rowStrengths[i].second);
        }

        return result;
    }
};
int main()
{
    Solution a;
    vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 1}};
    vector<int> res = a.kWeakestRows(mat, 3);
    return 0;
}