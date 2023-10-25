#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node *buildtree(node *&root)
{
    int data;
    cout << "\n data:";
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data to the left of " << data;
    root->left = buildtree(root->left);
    cout << "enter data to the right of " << data;
    root->right = buildtree(root->right);
    return root;
}
void display(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
vector<int> zigzag(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    bool directionLR = true;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();

            int index = directionLR ? i : size - i - 1;
            ans[index] = front->data;

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        directionLR = !directionLR;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}
void travleft(node *left, vector<int> &ans)
{
    if ((left == NULL) || (left->left == NULL && left->right == NULL))
    {
        return;
    }
    ans.push_back(left->data);
    if (left->left)
    {
        travleft(left->left, ans);
    }
    if (left->right)
    {
        travleft(left->right, ans);
    }
}
void travleaf(node *leaf, vector<int> &ans)
{
    if (leaf == NULL)
    {
        return;
    }
    if (leaf->left == NULL && leaf->right == NULL)
    {
        ans.push_back(leaf->data);
        return;
    }
    if (leaf->left)
    {
        travleaf(leaf->left, ans);
    }
    if (leaf->right)
    {
        travleaf(leaf->right, ans);
    }
}

void travright(node *right, vector<int> &ans)
{
    if ((right == NULL) || (right->left == NULL && right->right == NULL))
    {
        return;
    }
    if (right->right)
    {
        travright(right->right, ans);
    }
    else
    {
        travright(right->left, ans);
    }

    ans.push_back(right->data);
}
vector<int> boundarycondn(node *root)
{
    vector<int> ans;
    ans.push_back(root->data);

    travleft(root->left, ans);

    travleaf(root->left, ans);
    travleaf(root->right, ans);

    travright(root->right, ans);
    return ans;
}
vector<int> verticalorder(node *root)
{
    map<int, map<int, vector<int>>> nodes; // map of HD and level with list of nodes in 1 hd and level
    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0))); // HD and LVL  both 0 at first
    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontnode->data);

        if (frontnode->left)
        {
            q.push(make_pair(frontnode->left, make_pair(hd - 1, level + 1)));
        }
        if (frontnode->right)
        {
            q.push(make_pair(frontnode->right, make_pair(hd + 1, level + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{ // 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1
    node *root = NULL;
    buildtree(root);
    system("CLS");
    display(root);
    vector<int> zz = zigzag(root);
    return 0;
}