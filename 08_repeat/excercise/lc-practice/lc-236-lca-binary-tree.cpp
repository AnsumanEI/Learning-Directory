#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr && right == nullptr)
        {
            return nullptr;
        }
        else if (left == nullptr)
        {
            return right;
        }
        else if (right == nullptr)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
};
int main()
{

    return 0;
}