#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<pair<int, int>>> &adj, int src, int dest, int num_nodes)
{
    queue<int> node_tovisit;
    vector<bool> visited(num_nodes, false);
    vector<int> parent(num_nodes, -1);
    vector<int> dist(num_nodes, 0);

    parent[src] = src;
    node_tovisit.push(src);

    while (!node_tovisit.empty())
    {
        int curr_node = node_tovisit.front();
        visited[curr_node] = true;
        if (curr_node == dest)
        {
            break;
        }
        node_tovisit.pop();

        for (auto &p : adj[curr_node])
        {
            if (visited[p.first] == false)
            {
                node_tovisit.push(p.first);
                visited[p.first] = true;
                parent[p.first] = curr_node;
                dist[p.first] = dist[curr_node] + p.second;
            }
        }
    }
    int node = dest;
    vector<int> path;
    while (node != src)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);

    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i != 0)
        {
            cout << " -> ";
        }
    }
    cout << "\n";
    cout << "Bfs Distance : " << dist[dest];
}

void dfssolver(vector<vector<pair<int, int>>> &adj, int src, int dest, int num_nodes, vector<bool> &visited, vector<int> &parent, vector<int> &dist, int curr_node)
{
    if (curr_node == dest || adj[curr_node].empty())
    {
        return;
    }

    visited[curr_node] = true;
    for (auto &p : adj[curr_node])
    {
        if (visited[p.first] == false)
        {
            visited[p.first] = true;
            dist[p.first] = dist[curr_node] + p.second;
            parent[p.first] = curr_node;
            dfssolver(adj, src, dest, num_nodes, visited, parent, dist, p.first);
        }
    }
}
void dfs(vector<vector<pair<int, int>>> &adj, int src, int dest, int num_nodes)
{
    vector<bool> visited(num_nodes, false);
    vector<int> parent(num_nodes, -1);
    parent[src] = src;
    vector<int> dist(num_nodes, 0);
    dfssolver(adj, src, dest, num_nodes, visited, parent, dist, src);

    vector<int> path;
    int node = dest;
    while (node != src)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i != 0)
        {
            cout << " -> ";
        }
    }
    cout << "\n";
    cout << "DFS Distance : " << dist[dest];
}

void dijkstra(vector<vector<pair<int, int>>> &adj, int src, int dest, int num_nodes)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    vector<int> parent(num_nodes, -1);
    vector<int> dist(num_nodes, INT_MAX);
    vector<bool> visited(num_nodes, false);

    dist[src] = 0;
    minheap.push({dist[src], src});
    parent[src] = src;

    while (!minheap.empty())
    {
        auto curr_node = minheap.top();
        minheap.pop();
        visited[curr_node.second] = true;

        for (auto &p : adj[curr_node.second])
        {
            if (visited[p.first] == true)
            {
                continue;
            }
            int dist1 = curr_node.first + p.second;
            if (dist1 < dist[p.first])
            {
                minheap.push({dist1, p.first});
                dist[p.first] = dist1;
                parent[p.first] = curr_node.second;
            }
        }
    }

    vector<int> path;
    int node = dest;
    while (node != src)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i != 0)
        {
            cout << " -> ";
        }
    }
    cout << "\n";
    cout << "Dijkstra Distance : " << dist[dest];
}
int main()
{

    int source, destination, num_nodes, num_edges;
    vector<tuple<int, int, int>> inp_edges;
    cout << "Enter the nummber of node \n";
    cin >> num_nodes;
    cout << "Enter the nummber of edges \n";
    cin >> num_edges;

    vector<vector<pair<int, int>>> adj(num_nodes); // source -> dest,weight
    cout << "Enter the inputs: \n";
    for (int i = 0; i < num_edges; i++)
    {
        int u, v, w;
        cout << "Enter source dest weight for edge " << i << "\n";
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
    cout << "\n<--------------------BFS--------------------->\n";
    bfs(adj, source, destination, num_nodes);
    cout << "\n<--------------------DFS--------------------->\n";
    dfs(adj, source, destination, num_nodes);
    cout << "\n<--------------------DIJSKTRA--------------------->\n";
    dijkstra(adj, source, destination, num_nodes);

    return 0;
}