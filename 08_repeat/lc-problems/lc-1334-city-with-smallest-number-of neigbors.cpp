#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for (auto &p : edges)
        {
            int u = p[0];
            int v = p[1];
            int w = p[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int reachable = 0;
        int minreachable = n;
        int best = -1;
        for (int i = 0; i < n; i++)
        {
            reachable = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && dist[i][j] <= distanceThreshold)
                {
                    reachable++;
                }
            }
            if (reachable <= minreachable)
            {
                minreachable = reachable;
                best = i;
            }
        }
        return best;
    }
};
int main()
{

    return 0;
}