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
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> pusher;
        TreeNode *current = root;
        TreeNode *prev = nullptr;

        while (!pusher.empty() || current != nullptr)
        {
            while (current != nullptr)
            {
                pusher.push(current);
                current = current->left;
            }
            current = pusher.top();
            pusher.pop();
            if (prev != nullptr && prev->val >= current->val)
            {
                return false;
            }
            prev = current;
            current = current->right;
        }
        return true;
    }

    bool checker(TreeNode *root, TreeNode *&prev)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (!checker(root->left, prev))
            return false;

        if (prev != nullptr && prev->val >= root->val)
        {
            return false;
        }
        prev = root;
        if (!checker(root->right, prev))
            return false;
    }
    bool ValidateRec(TreeNode *root)
    {
        TreeNode *prev = nullptr;
    }
};
int main()
{

    return 0;
}