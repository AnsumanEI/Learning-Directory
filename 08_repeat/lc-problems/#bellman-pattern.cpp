#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bellmanford(vector<vector<int>> &times, int n, int k)
    { // times -> source , dest , weight
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        for (int i = 1; i < n; i++)
        {
            for (auto &p : times)
            {
                int u = p[0];
                int v = p[1];
                int w = p[2];

                if (dist[u] != INT_MAX /* if we dont know the source value */ && dist[u] + w < dist[v]) // mew dist > prev
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        // negative cycle check , see n-1 loops are done if still the distance is improvinf that means there is a negative weight
        for (auto &p : times)
        {
            int u = p[0];
            int v = p[1];
            int w = p[2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                return {};
            }
        }
        return dist;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> res = bellmanford(times, n, k);
        int maxres = *max_element(res.begin() + 1, res.end());

        return maxres == INT_MAX ? -1 : maxres;
    }
};
int main()
{
    return 0;
}