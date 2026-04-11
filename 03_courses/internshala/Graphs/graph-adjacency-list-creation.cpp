#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, vector<int>> adjList;

void addEdge(int fromNode, int toNode, bool isUndirected) {
    adjList[fromNode].push_back(toNode);
    if (isUndirected) {
        adjList[toNode].push_back(fromNode);
    }
}

void printAdjList() {
    for (auto node : adjList) {
        cout << node.first << " -> ";
        for (auto neighbor : node.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    // Enter number of nodes: 4
    // Enter number of edges: 4
    // Then enter each edge as two numbers: 1 2, 2 3, 3 4, 4 1
    
    int numNodes, numEdges;
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    cout << "Enter number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int fromNode, toNode;
        cout << "Enter edge (fromNode toNode): ";
        cin >> fromNode >> toNode;
        addEdge(fromNode, toNode, true); // true = undirected
    }

    printAdjList();
    return 0;
}
