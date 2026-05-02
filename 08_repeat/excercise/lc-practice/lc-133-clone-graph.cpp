#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
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
    Node *dfs(Node *root, unordered_map<Node *, Node *> &cloned)
    {
        if (root == nullptr)
            return nullptr;
        if (cloned.count(root))
            return cloned[root];

        Node *clone = new Node(root->val);
        cloned[root] = clone;
        for (auto &p : root->neighbors)
        {
            clone->neighbors.push_back(dfs(p, cloned));
        }
        return clone;
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