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
    void solver(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &curr, int sum, int ind)
    {
        if (sum > target)
        {
            return;
        }

        if (sum == target)
        {
            res.push_back(curr);
            return;
        }

        for (int i = ind; i < candidates.size(); i++)
        {
            curr.push_back(candidates[i]);
            solver(candidates, target, res, curr, sum + candidates[i], i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        solver(candidates, target, result, current, 0, 0);
        return result;
    }
};
int main()
{

    return 0;
}