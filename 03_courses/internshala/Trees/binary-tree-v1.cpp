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
    cout << "enter data :" << endl;
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the value for left of " << data << ":\n";
    root->left = buildtree(root->left);

    cout << "enter the value for right of " << data << ":\n";
    root->right = buildtree(root->right);
    return root;
}
void buildfromlevelorder(node *&root)
{
    queue<node *> q;
    cout << "\n enter the data :";
    int data;
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
} // 1 2 3 -1 -1 4 -1 -1 5 6 -1 8 -1 -1 7 9 -1 -1 -1
int main()
{
    node *root;
    buildtree(root);
    cout << "print \n";
    levelordertrav(root);
    return 0;
}