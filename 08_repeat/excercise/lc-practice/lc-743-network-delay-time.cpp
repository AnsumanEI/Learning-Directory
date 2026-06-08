#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        minheap.push({0, k});
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        for (auto &p : times)
        {
            int u = p[0];
            int v = p[1]; // dest
            int w = p[2];

            adj[u].push_back({v, w});
        }

        while (!minheap.empty())
        {
            auto current = minheap.top();
            minheap.pop();

            for (auto &p : adj[current.second])
            {
                int disttotal = current.first + p.second;
                if (disttotal < dist[p.first])
                {
                    dist[p.first] = disttotal;
                    minheap.push({disttotal, p.first});
                }
            }
        }
        int max = *max_element(dist.begin() + 1, dist.end());
        return max == INT_MAX ? -1 : max;
    }
};
int main()
{

    return 0;
}