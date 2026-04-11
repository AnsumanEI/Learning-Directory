#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ----------------------------------------------------------------
//  NODE DEFINITION (LeetCode graph node)
// ----------------------------------------------------------------

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors({}) {}
    Node(int x) : val(x), neighbors({}) {}
    Node(int x, vector<Node*> adj) : val(x), neighbors(adj) {}
};

// ----------------------------------------------------------------
//  LeetCode #133 — Clone Graph
// ----------------------------------------------------------------
//
//  PROBLEM:
//  Given a reference to a node in a connected undirected graph,
//  return a deep copy (clone) of the graph.
//
//  INTUITION:
//  DFS through the original graph, creating a clone for each node
//  as we first visit it. A hash map from original → clone lets us
//  avoid infinite loops on cycles and reuse already-cloned nodes
//  when wiring up neighbors.
//
//  APPROACH: DFS + Hash Map
//
//    - Base case: null node → return null.
//    - If node is already in visited map, return its clone
//      (handles cycles and shared references).
//    - Otherwise create a new clone, store it in the map, then
//      recursively clone each neighbor and push to clone's list.
//
//  COMPLEXITY:
//    Time  : O(V + E) — visit every node and edge once
//    Space : O(V)     — hash map + call stack
//
//  MISTAKES TO AVOID:
//  ❌ Not checking visited before recursing → infinite loop on cycles
//  ✅ Store clone in map BEFORE recursing into neighbors
// ----------------------------------------------------------------

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (node == nullptr)
            return nullptr;
        if (visited.count(node))
            return visited[node];

        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }
};

// ----------------------------------------------------------------
//  MAIN — Test LC #133
// ----------------------------------------------------------------

int main() {
    // Build graph: 1 -- 2
    //              |    |
    //              4 -- 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Solution sol;
    Node* cloned = sol.cloneGraph(n1);

    // Verify: cloned node should be a different pointer but same value
    cout << "Original node 1 address : " << n1 << "\n";
    cout << "Cloned   node 1 address : " << cloned << "\n";
    cout << "Cloned   node 1 value   : " << cloned->val << " (expect 1)\n";
    cout << "Cloned   node 1 neighbors: ";
    for (Node* nb : cloned->neighbors)
        cout << nb->val << " ";
    cout << "(expect 2 4)\n";

    return 0;
}
