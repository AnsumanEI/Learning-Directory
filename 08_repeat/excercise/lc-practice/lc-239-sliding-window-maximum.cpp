#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
#include <deque>
using namespace std;
class Solution
{
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result ;
        deque<int> max ;
        int l=0 ;
        int r= 0;
        while(r<nums.size()){
            while(!max.empty() && nums[max.back()] < nums[r]){
                max.pop_back();
            }
            max.push_back(r);

            if(max.front()<l)
            {
                max.pop_front();
            }

            if(r>= k-1)
            {
                result.push_back(nums[max.front()]);
                l++;
            }
            r++;
        }
        return result;
    }
};
int main()
{

return 0;
}