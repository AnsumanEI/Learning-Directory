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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        int tar = k;
        int h;

        while (curr != nullptr || !stack.empty())
        {
            while (curr != nullptr)
            {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            k--;
            if (k == 0)
            {
                h = curr->val;
                return h;
            }
            stack.pop();
            curr = curr->right;
        }
        return h;
    }
};
int main()
{

    return 0;
}