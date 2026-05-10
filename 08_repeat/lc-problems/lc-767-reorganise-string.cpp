#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reorganizeString(string s)
    {
        priority_queue<pair<int, char>> maxheap;
        string res;
        int n = s.size();
        unordered_map<char, int> freq;
        pair<int, char> prev;
        prev.first = 0;
        prev.second = {};
        for (auto &p : s)
        {
            freq[p]++;
            if (freq[p] > (n + 1) / 2)
            {
                return {};
            }
        }

        for (auto &p : freq)
        {
            maxheap.push({p.second, p.first});
        }
        while (!maxheap.empty())
        {
            int num = maxheap.top().first;
            char chr = maxheap.top().second;
            maxheap.pop();

            res.push_back(chr);

            if (prev.first > 0)
            {
                maxheap.push({prev.first, prev.second});
            }
            prev = {num - 1, chr};
        }
        return res;
    }
};
int main()
{

    return 0;
}