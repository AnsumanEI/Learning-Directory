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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto &p : nums)
        {
            freq[p]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        for (auto &p : freq)
        {
            minheap.push({p.second, p.first});
            if (minheap.size() > k)
            {
                minheap.pop();
            }
        }
        vector<int> res;
        while (!minheap.empty())
        {
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
    }
};
int main()
{

    return 0;
}