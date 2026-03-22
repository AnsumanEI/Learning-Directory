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
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = l = (r - l) / 2;
        while (l <= r)
        {
            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid - 1] || nums[mid] == nums[mid + 1])
                {
                    break;
                }
            }
        }
    }
};
int main()
{

    return 0;
}