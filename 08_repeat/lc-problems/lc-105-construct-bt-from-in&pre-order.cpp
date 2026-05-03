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
    TreeNode *buildTree(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map<int, int> &inmap)
    {
        if (prestart > preend || instart > inend)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[prestart]);

        int rootpos = inmap[preorder[prestart]]; // or inmap[preorder[root->val]]
        int leftsize = rootpos - instart;
        root->left = buildTree(preorder, prestart + 1, prestart + leftsize, inorder, instart, rootpos - 1, inmap); // i doubt why did theleft prestart end = is not  prestart +1 + leftsize
        root->right = buildTree(preorder, prestart + leftsize + 1, preend, inorder, rootpos + 1, inend, inmap);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) // inorder size because we will be searching in this first after deciding root
        {
            inmap[inorder[i]] = i;
        }

        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
    }
};
int main()
{

    return 0;
}