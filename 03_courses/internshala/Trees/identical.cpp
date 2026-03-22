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
    node *left;
    node *right;
    int data;
    node(int data = 999)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void buildtree(node *&root)
{
    int data1;
    cout << "enter the data : ";
    cin >> data1;

    queue<node *> q;
    root = new node(data1);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "enter the data for left 0f " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "enter the data for right 0f " << temp->data << endl;
        int rightd;
        cin >> rightd;
        if (rightd != -1)
        {
            temp->right = new node(rightd);
            q.push(temp->right);
        }
    }
}
bool compare(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 != NULL && root2 == NULL)
        return false;
    if (root1 == NULL && root2 != NULL)
        return false;

    bool left = compare(root1->left, root2->left);
    bool right = compare(root1->right, root2->right);
    bool value = root1->data == root2->data;
    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}
pair<bool, int> isSum(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSum(root->left);
    pair<bool, int> right = isSum(root->right);

    bool cleft = left.first;
    bool cright = right.first;
    bool condn = root->data == left.second + right.second;
    pair<bool, int> ans;
    if (cleft && cright && condn)
    {
        ans.second = 2 * root->data;
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

int main()
{
    // 1 2 3 4 5 6 99 -1 -1 -1 -1 7 -1 -1 -1 -1 -1
    // 19 29 39 49 59 69 99 -1 -1 -1 -1 7 -1 -1 -1 -1 -1
    // 3 1 2 -1 -1 1 1  -1 -1 -1 -1
    node *root1;
    // node *root2;
    buildtree(root1);
    // buildtree(root2);
    system("CLS");
    // cout << compare(root1, root2);
    cout << isSum(root1).first << " ";

    return 0;
}