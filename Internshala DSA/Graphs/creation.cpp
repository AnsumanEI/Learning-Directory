#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
template <typename T> // to make it generic and store whatever we want
class graph
{
public:
    unordered_map<T, list<T>> adj;
    void addedge(T u, T v, bool direction)
    {
        // direction 0-> undirected 1-> directed graph
        // create edge from u to v

        adj[u].push_back(v);
        if (!direction) // if 0 then only v to u and u to v
        {
            adj[v].push_back(u);
        }
    }
    void printadjlist()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            {
                for (auto j : i.second)
                {
                    cout << j << ",";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "enter the number of nodes ";
    cin >> n;
    cout << endl;
    cout << "enter the number of edges ";
    cin >> m;
    graph<int> g; // template type is int
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0); // undirected
    }
    g.printadjlist();
    return 0;
}