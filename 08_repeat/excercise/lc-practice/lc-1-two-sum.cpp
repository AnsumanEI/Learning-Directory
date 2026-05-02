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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int comp;
        unordered_map<int, int> findcomp;
        for (int i = 0; i < nums.size(); i++)
        {
            comp = target - nums[i];

            if (findcomp.find(comp) != findcomp.end())
            {
                return {findcomp[comp], i};
            }
            findcomp[nums[i]] = i;
        }
    }
};
int main()
{

    return 0;
}