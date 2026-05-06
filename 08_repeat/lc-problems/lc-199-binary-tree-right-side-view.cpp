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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> q;
        int size;
        if (root == nullptr)
            return res;

        q.push(root);
        while (!q.empty())
        {
            size = q.size();
            TreeNode *out;
            for (int i = 1; i <= size; i++)
            {
                TreeNode *temp = q.front();
                out = temp;
                q.pop();
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
            res.push_back(out->val);
        }
        return res;
    }
};
int main()
{

    return 0;
}