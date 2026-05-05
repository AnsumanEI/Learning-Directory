#include <iostream>
#include "bst.h"

using namespace std;

Node *BST::minNode(Node *root)
{
    while (root->LeftNode != nullptr)
    {
        root = root->LeftNode;
    }
    return root;
}
Node *BST::insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }
    if (val < root->Value)
    {
        root->LeftNode = insert(root->LeftNode, val);
    }
    else
    {
        root->RightNode = insert(root->RightNode, val);
    }
    return root;
};
Node *BST::del(Node *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (val < root->Value)
    {
        root->LeftNode = del(root->LeftNode, val);
    }
    else if (val > root->Value)
    {
        root->RightNode = del(root->RightNode, val);
    }
    else
    {
        if (root->LeftNode == nullptr && root->RightNode == nullptr)
        {
            return nullptr;
        }
        else if (root->RightNode == nullptr)
        {
            return root->LeftNode;
        }
        else if (root->LeftNode == nullptr)
        {
            return root->RightNode;
        }
        else
        {
            Node *inorderSuccesor = minNode(root->RightNode);
            root->Value = inorderSuccesor->Value;
            root->RightNode = del(root->RightNode, inorderSuccesor->Value);
        }
    }
    return root;
};
bool BST::search(Node *root, int val)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->Value == val)
    {
        return true;
    }
    if (root->Value > val)
    {
        if (search(root->LeftNode, val))
        {
            return true; // no need to right because it wont match nullptr check will send false , and if matches true
        }
    }
    else
    {
        if (search(root->RightNode, val))
        {
            return true;
        }
    }
    return false;
};
void BST::inorder(Node *root, vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->LeftNode, res);
    res.push_back(root->Value);
    inorder(root->RightNode, res);
};
void BST::preorder(Node *root, vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }
    res.push_back(root->Value);
    preorder(root->LeftNode, res);
    preorder(root->RightNode, res);
};
void BST::postorder(Node *root, vector<int> &res)
{

    if (root == nullptr)
    {
        return;
    }

    postorder(root->LeftNode, res);
    postorder(root->RightNode, res);
    res.push_back(root->Value);
};
int BST::height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = height(root->LeftNode);
    int right = height(root->RightNode);
    return max(left, right) + 1;
};
Node *BST::lca(Node *root, int p, int q)
{
    if (root == nullptr)
        return nullptr;
    if (p < root->Value && q < root->Value)
    {
        return lca(root->LeftNode, p, q);
    }
    if (p > root->Value && q > root->Value)
    {
        return lca(root->RightNode, p, q);
    }
    else
    {
        return root;
    }
};

void BST::insert(int value)
{
    root = insert(root, value);
};
void BST::del(int value)
{
    root = del(root, value);
};
bool BST::search(int value)
{
    return search(root, value);
};
vector<int> BST::preorder()
{
    vector<int> res;
    preorder(root, res);
    return res;
};
vector<int> BST::inorder()
{
    vector<int> res;
    inorder(root, res);
    return res;
};
vector<int> BST::postorder()
{
    vector<int> res;
    postorder(root, res);
    return res;
};
int BST::height()
{
    return height(root);
};
Node *BST::lca(int p, int q)
{
    return lca(root, p, q);
};
