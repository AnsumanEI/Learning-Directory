#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool issametree(TreeNode *p, TreeNode *subroot)
    {
        if (p == nullptr && subroot == nullptr)
        {
            return true;
        }
        if (p == nullptr || subroot == nullptr)
        {
            return false;
        }
        if (p->val != subroot->val)
        {
            return false;
        }
        bool left = issametree(p->left, subroot->left);
        bool right = issametree(p->right, subroot->right);

        return left && right;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
        {
            return false;
        }
        else if (root->val == subRoot->val)
        {
            if (issametree(root, subRoot))
            {
                return true;
            }
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);

        return left || right;
    }
};
int main()
{

    return 0;
}