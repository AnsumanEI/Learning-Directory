#include <bits/stdc++.h>
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
        queue<TreeNode *> tasks;
        string res;

        tasks.push(root);
        while (!tasks.empty())
        {
            TreeNode *temp = tasks.front();
            tasks.pop();

            if (temp == nullptr)
            {
                res += "N";
            }
            else
            {
                res += to_string(temp->val);
                tasks.push(temp->left);
                tasks.push(temp->right);
            }
            res += ",";
        }
        if (!res.empty())
        {
            res.pop_back();
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }
        stringstream ss(data);
        string token;
        queue<string> q;

        while (getline(ss, token, ','))
        {
            q.push(token);
        }

        if (q.front() == "N")
        {
            return nullptr;
        }

        queue<TreeNode *> nodeq;
        int value = stoi(q.front());
        TreeNode *root = new TreeNode(value);
        q.pop();

        nodeq.push(root);
        while (!nodeq.empty())
        {
            TreeNode *curr = nodeq.front();
            nodeq.pop();
            string left = q.front();
            q.pop();
            string right = q.front();
            q.pop();

            if (left != "N")
            {
                curr->left = new TreeNode(stoi(left));
                nodeq.push(curr->left);
            }
            else
            {
                curr->left = nullptr;
            }

            if (right != "N")
            {
                curr->right = new TreeNode(stoi(right));
                nodeq.push(curr->right);
            }
            else
            {
                curr->right = nullptr;
            }
        }
        return root;
    }
};

int main()
{

    return 0;
}