#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
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
    bool isSametree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;
        else if (root == nullptr || subRoot == nullptr)
            return false;
        else if (root->val != subRoot->val)
            return false;
        bool left = isSametree(root->left, subRoot->left);
        bool right = isSametree(root->right, subRoot->right);
        return left && right;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;
        else if (root->val == subRoot->val)
        {
            if (isSametree(root, subRoot))
                return true;
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