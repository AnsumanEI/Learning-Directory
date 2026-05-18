#include <bits/stdc++.h>
using namespace std;

vector<int> dijsktra(vector<vector<int>> &times, int n, int k) // 1 to n
{
    vector<vector<pair<int, int>>> adj(n + 1); // double vector as each node can have multiple neigbors

    for (auto &p : times)
    {
        int source = p[0];
        int dest = p[1];
        int weight = p[2];

        adj[source].push_back({dest, weight});
    }

    vector<int> dist(n + 1, INT_MAX); // 1 TO N

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap; // cost,node

    dist[k] = 0; // seeding the source 0

    minheap.push({0, k});

    while (!minheap.empty())
    {
        pair<int, int> toprocess = minheap.top(); // cost,node
        minheap.pop();
        if (toprocess.first > dist[toprocess.second])
        {
            continue;
        }
        for (auto &p : adj[toprocess.second])
        { // p  node ,cost
            int distance = toprocess.first + p.second;
            if (distance < dist[p.first])
            {
                dist[p.first] = distance;
                minheap.push({distance, p.first});
            }
        }
    }
    return dist;
}

int main()
{
    return 0;
}