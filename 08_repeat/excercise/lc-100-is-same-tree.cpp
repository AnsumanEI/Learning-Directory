#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        val = NULL;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr || q == nullptr)
            return false;
        else if (p->val != q->val)
            return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return left && right;
    }

    bool isSameTreeStack(TreeNode *p, TreeNode *q)
    {
        stack<pair<TreeNode *, TreeNode *>> visited;

        visited.push({p, q});

        while (!visited.empty())
        {
            auto [node1, node2] = visited.top();
            visited.pop();

            if (node1 == nullptr && node2 == nullptr)
                continue;
            else if (node1 == nullptr || node2 == nullptr)
                return false;
            else if (node1->val != node2->val)
                return false;

            visited.push({node1->left, node2->left});
            visited.push({node1->right, node2->right});
        }
        return true;
    }
};
int main()
{

    return 0;
}
