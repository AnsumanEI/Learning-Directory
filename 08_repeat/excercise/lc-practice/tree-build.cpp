#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode (int val)
    {
        left = nullptr;
        right = nullptr;
        this->val = val;
    }
};
void buildTree(TreeNode *& root)//i dont understand this why *&
{
    int val ;
    cin>>val ;

    if(val == -1) return ; // i want to quit making trees if value -- -1
    root = new TreeNode(val);

    buildTree(root->left);
    buildTree(root->right);
}

void inorder(TreeNode * root)
{
    if (root == nullptr ) return;

    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}
int breadFS(TreeNode* root)
{
    queue<TreeNode*> q ;

    q.push(root);
    int depth  = 0;

    if(root == nullptr) return 0;

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0 ; i< size ; i++)
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        depth++;

    }
    return depth;
}

int main()
{

return 0;
}