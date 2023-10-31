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

    node(int data = 0)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
// recursive tree creation
node *buildtree(node *&root)
{
    int data;
    cout << "enter data:";
    cin >> data;

    if (data == -1)
    {
        return root;
    }
    root = new node(data);
    cout << "left of " << data << "\n";
    buildtree(root->left);
    cout << "right of " << data << "\n";
    buildtree(root->right);
    return root;
}
// recursive display
void displayrec(node *root)
{
    cout << root->data;
    if (root->left)
    {
        displayrec(root->left);
    }
    if (root->right)
    {
        displayrec(root->right);
    }
}
// level order creation of tree
void buildtreelot(node *&root)
{
    queue<node *> q;
    int data;
    cout << "enter data :";
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "enter the left of " << temp->data;
        int ldata;
        cin >> ldata;
        if (ldata != -1)
        {
            temp->left = new node(ldata);
            q.push(temp->left);
        }

        cout << "enter the right of " << temp->data;
        int rdata;
        cin >> rdata;
        if (rdata != -1)
        {
            temp->right = new node(rdata);
            q.push(temp->right);
        }
    }
}
// level order display
void displaylot(node *root)
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
            cout << temp->data;
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
int getheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = getheight(root->left);
    int right = getheight(root->right);

    int ans = max(left, right) + 1;
    return ans;
}
int main()
{
    node *root = NULL;
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 7 -1 -1 -1

    displaylot(root);
    return 0;
}