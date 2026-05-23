#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k)
    {

        vector<vector<pair<int, int>>> adj(n);
        for (auto &p : flights)
        {
            int u = p[0];
            int v = p[1];
            int price = p[2];

            adj[u].push_back({v, price});
        }
        int inf = 1e9;

        vector<int> prices(n, inf);
        prices[src] = 0;

        queue<tuple<int, int, int>> q;
        q.push({0, src, 0});

        while (!q.empty())
        {
            auto [stops, node, cost] = q.front();
            q.pop();

            if (stops > k)
            {
                continue;
            }
            for (auto &p : adj[node])
            {
                int city = p.first;
                int price = p.second;

                if (cost + price < prices[city])
                {
                    prices[city] = cost + price;
                    q.push({stops + 1, city, cost + price});
                }
            }
        }

        if (prices[dst] == inf)
        {
            return -1;
        }
        return prices[dst];
    }
};
int main()
{

    return 0;
}