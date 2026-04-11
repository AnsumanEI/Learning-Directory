#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;

class node {
    public:
    int val;
    node(){
        val = NULL;
    }
    node(int val)
    {
        this->val = val ;
    }
    vector<node*> neighbors;

node * dfs(node * Node , unordered_map<node* , node* > &visited){
    if (Node == nullptr) return nullptr;
    else if(visited.count(Node)) return visited[Node];

    node * clone = new node(Node->val);
    visited[Node] = clone ;
    for(node* p : Node->neighbors){
        clone->neighbors.push_back(dfs( p , visited));
    }
    return clone;
};
};


int main()
{

return 0;
}