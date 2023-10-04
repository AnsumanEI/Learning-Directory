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

    node(int data = 0)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node *buildtree(node *&root)
{
    int data;
    cout << "Enter the data :";
    cin >> data;
    cout << endl;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data for left of " << root->left << endl;
    root->left = buildtree(root->left);
    cout << "enter the data for right of " << root->right << endl;
    root->right = buildtree(root->right);
    return root;
}

void levelordertrav(node *root)
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

void lvlordtravbuild(node *&root)
{
    queue<node *> q;
    int data;
    cout << "enter the data : ";
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "enter left node for: " << temp->left << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "enter right node for: " << temp->right << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelordertrav(root);
    return 0;
}