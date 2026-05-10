#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq;
        priority_queue<int> maxheap;
        queue<pair<int, int>> cooldown;
        int time = 0;
        for (auto &p : tasks)
        {
            freq[p]++;
        }

        for (auto &p : freq)
        {
            maxheap.push({p.second});
        }

        while (!cooldown.empty() || !maxheap.empty())
        {
            while (!cooldown.empty() && cooldown.front().second <= time)
            {
                int tp = cooldown.front().first;
                maxheap.push(tp);
                cooldown.pop();
            }
            if (!maxheap.empty())
            {
                int temp = maxheap.top();
                maxheap.pop();
                if (temp - 1 != 0)
                {
                    cooldown.push({temp - 1, time + n + 1});
                }
            }

            time++;
        }
        return time;
    }
};
int main()
{

    return 0;
}