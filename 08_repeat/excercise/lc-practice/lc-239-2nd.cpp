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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int l = 0;
        int r = 0;
        deque<int> dq;
        vector<int> res;
        while (r < nums.size())
        {
            while (!dq.empty() && nums[r] > nums[dq.back()])
            {
                dq.pop_back();
            }

            if (!dq.empty() && dq.front() < l)
            {
                dq.pop_front();
            }

            dq.push_back(r);

            if (r >= k - 1)
            {
                res.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return res;
    }
};
int main()
{

    return 0;
}