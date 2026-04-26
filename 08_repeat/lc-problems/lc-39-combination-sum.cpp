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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target, int sumfal, int ind, vector<int> &curr, vector<vector<int>> &res)
    {

        for (int i = ind; i < candidates.size(); i++)
        {
            int sum = candidates[i] + sumfal;

            if (sum < target)
            {
                curr.push_back(candidates[i]);
                combinationSum(candidates, target, sum, i, curr, res);
                curr.pop_back();
            }
            else if (sum == target)

            {
                curr.push_back(candidates[i]);
                res.push_back(curr);
                curr.pop_back();
            }
        }
    }
};
int main()
{

    return 0;
}