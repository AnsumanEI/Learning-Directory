#include <bits/stdc++.h>
using namespace std;
class disjointset
{
    vector<int> rank, parent, sizevec;

public:
    disjointset(int n)
    {
        rank.resize(n + 1, 0); // works for both 0 based indexing and 1 based indexing so n+1
        parent.resize(n + 1);
        sizevec.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUparent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        // also we have to to the path compression too
        return parent[node] = findUparent(parent[node]);
    }
    void unionbyrank(int u, int v)
    {
        int pu = findUparent(u);
        int pv = findUparent(v);

        if (pu == pv)
        {
            return;
        }

        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pv] > rank[pu])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    void unionbysize(int u, int v)
    {
        int pu = findUparent(u);
        int pv = findUparent(v);

        if (pu == pv)
        {
            return;
        }

        if (sizevec[pu] > sizevec[pv])
        {
            parent[pv] = pu;
            sizevec[pu] += sizevec[pv];
        }
        else
        {
            parent[pu] = pv;
            sizevec[pv] += sizevec[pu];
        }
    }
};
int main()
{

    return 0;
}