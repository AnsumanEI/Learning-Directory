#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void solver(vector<int> &nums, vector<vector<int>> &res, vector<int> &visited, vector<int> &curr)
{
    if (curr.size() == nums.size())
    {
        res.push_back(curr);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            curr.push_back(nums[i]);
            solver(nums, res, visited, curr);
            visited[i] = false;
            curr.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> visited(nums.size(), false);
}
int main()
{

    return 0;
}