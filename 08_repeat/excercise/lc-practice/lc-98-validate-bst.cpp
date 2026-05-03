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
        TreeNode *prev = nullptr;
        stack<TreeNode *> stack;
        TreeNode *current = root;
        while (!stack.empty() || current != nullptr)
        {
            while (current != nullptr)
            {
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            stack.pop();
            if (prev != nullptr && current->val <= prev->val)
            {
                return false;
            }
            prev = current;
            current = current->right;
        }
        return true;
    }
};
int main()
{

    return 0;
}