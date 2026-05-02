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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        prefix[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        suffix[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(prefix[i] * suffix[i]);
        }
        return res;
    }
};
int main()
{

    return 0;
}