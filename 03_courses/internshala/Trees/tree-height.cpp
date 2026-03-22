#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *buildtree(node *&root)
{
    int data;

    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    root->left = buildtree(root->left);

    root->right = buildtree(root->right);
    return root;
}
// question 1
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
// question 2
pair<int, int> diameterfast(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = {0, 0};
        return p;
    }
    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(node *root)
{
    return diameterfast(root).first; // diametere only
}

// check for balanced tree
bool isbalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool left = isbalanced(root->left);
    bool right = isbalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 8 -1 -1 7 9 -1 -1 -1
    node *root = NULL;
    buildtree(root);
    cout << "height :: " << height(root);
    cout << "diameter :: " << diameter(root);
    return 0;
}