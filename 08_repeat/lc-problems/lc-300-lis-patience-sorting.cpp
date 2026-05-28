#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        vector<int> tail;
        tail.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {

            auto it = lower_bound(tail.begin(), tail.end(), nums[i]);
            if (it == tail.end())
            {
                tail.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }
        }
        return tail.size();
    }
};
int main()
{

    return 0;
}