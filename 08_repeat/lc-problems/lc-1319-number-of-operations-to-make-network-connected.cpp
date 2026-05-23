#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> size, parent;
    void setup(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int finduparent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = finduparent(parent[node]);
    }
    bool unionbysize(int u, int v)
    {
        int pu = finduparent(u);
        int pv = finduparent(v);

        if (pu == pv)
        {
            return false;
        }

        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        return true;
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
        {
            return -1;
        }
        int num_cables = 0;
        int num_networks = 0;

        setup(n);
        for (auto &p : connections)
        {
            int u = p[0];
            int v = p[1];

            unionbysize(u, v);
        }

        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                num_networks++;
            }
        }
        return num_networks - 1; // to connect c computers we need c-1 cables
    }
};
int main()
{
    return 0;
}