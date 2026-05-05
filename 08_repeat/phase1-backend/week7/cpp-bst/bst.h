#pragma once
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
public:
    int Value;
    Node *LeftNode;
    Node *RightNode;
    Node()
    {
        LeftNode = nullptr;
        RightNode = nullptr;
    }
    Node(int Value)
    {
        this->Value = Value;
        LeftNode = nullptr;
        RightNode = nullptr;
    }
    Node(int Value, Node *left, Node *right)
    {
        this->Value = Value;
        LeftNode = left;
        RightNode = right;
    }
};

class BST
{
private:
    Node *root;

    Node *minNode(Node *root);
    Node *insert(Node *root, int val);
    Node *del(Node *root, int val);
    bool search(Node *root, int val);
    void inorder(Node *root, vector<int> &res);
    void preorder(Node *root, vector<int> &res);
    void postorder(Node *root, vector<int> &res);
    int height(Node *root);
    Node *lca(Node *root, int p, int q);

public:
    BST() { root = nullptr; }
    void insert(int val);
    void del(int val);
    bool search(int val);
    vector<int> inorder();
    vector<int> preorder();
    vector<int> postorder();
    int height();
    Node *lca(int p, int q);
};