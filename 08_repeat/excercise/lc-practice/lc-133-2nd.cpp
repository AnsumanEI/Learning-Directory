#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &cloned)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (cloned.count(node))
        {
            return cloned[node];
        }
        Node *newnode = new Node(node->val);
        cloned[node] = newnode;
        for (auto &p : node->neighbors)
        {
            newnode->neighbors.push_back(dfs(p, cloned));
        }
        return newnode;
    }
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> cloned;
        return dfs(node, cloned);
    }
};
int main()
{

    return 0;
}