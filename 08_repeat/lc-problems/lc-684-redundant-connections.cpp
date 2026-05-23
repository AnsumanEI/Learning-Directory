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
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        setup(edges.size());
        for (auto &p : edges)
        {
            int u = p[0];
            int v = p[1];

            if (unionbysize(u, v) == false)
            {
                return p;
            }
        }
        return {};
    }
};
int main()
{

    return 0;
}