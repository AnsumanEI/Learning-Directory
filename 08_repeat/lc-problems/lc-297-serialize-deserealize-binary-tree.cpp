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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "N";

        queue<TreeNode *> q;
        q.push(root);
        string res;

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == nullptr)
            {
                res += "N,";
            }
            else
            {
                res += to_string(temp->val) + ",";
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        if (!res.empty())
            res.pop_back(); // remove trailing comma
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;

        stringstream ss(data);
        string token;
        queue<string> q;
        while (getline(ss, token, ','))
            q.push(token);

        if (q.front() == "N")
            return nullptr;

        TreeNode *root = new TreeNode(stoi(q.front()));
        q.pop();

        queue<TreeNode *> nodeQ;
        nodeQ.push(root);

        while (!nodeQ.empty())
        {
            TreeNode *curr = nodeQ.front();
            nodeQ.pop();

            // Assign left child
            string left = q.front();
            q.pop();
            if (left != "N")
            {
                curr->left = new TreeNode(stoi(left));
                nodeQ.push(curr->left);
            }
            else
            {
                curr->left = nullptr;
            }

            // Assign right child
            string right = q.front();
            q.pop();
            if (right != "N")
            {
                curr->right = new TreeNode(stoi(right));
                nodeQ.push(curr->right);
            }
            else
            {
                curr->right = nullptr;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main()
{

    return 0;
}