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
        TreeNode *curr = root;
        stack<TreeNode *> stack;
        int count = k;
        while (curr != nullptr || !stack.empty())
        {
            while (curr != nullptr)
            {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            count--;
            if (count == 0)
                return curr->val;
            curr = curr->right;
        }
    }
};
int main()
{

    return 0;
}