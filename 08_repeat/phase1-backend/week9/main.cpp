#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<pair<int, int>>> &adj, int src, int dest, int n)
{
    queue<pair<int, int>> transporter; // parent + weight
    vector<int> visit_parent(n, -1);   // visitor
    visit_parent[src] = 1;
}
int main()
{

    int source, destination, num_nodes, num_edges;
    vector<tuple<int, int, int>> inp_edges;
    cout << "Enter the nummber of node \n";
    cin >> num_nodes;
    cout << "Enter the nummber of edges \n";
    cin >> num_edges;

    vector<vector<pair<int, int>>> adj(num_nodes);
    cout << "Enter the inputs: \n";
    for (int i = 0; i < num_edges; i++)
    {
        int u, v, w;
        cout << "Enter source dest weight \n";
        cin >> u >> v >> w;
        cout << "\n";
        inp_edges.push_back({u, v, w});
    }

    cout << "Enter source and destination in order : \n";
    cin >> source >> destination;

    for (auto &p : inp_edges)
    {
        int u = get<0>(p);
        int v = get<1>(p);
        int w = get<2>(p);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return 0;
}