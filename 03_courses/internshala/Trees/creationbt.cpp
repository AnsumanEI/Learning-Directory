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
        this->left = NULL;
        this->right = NULL; // can be written without this too
    }
};
node *buildnode(node *&root)
{
    int data;
    cout << "enter the data :";
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the left data of " << data << endl;
    root->left = buildnode(root->left);
    cout << "enter the right data of  " << data << endl;
    root->right = buildnode(root->right);
    return root;
}
void levelordertraversal(node *root) // print 1 level at a time from top to bottom to make it look like a tree
{                                    // also calle breadth first search
    queue<node *> q;
    q.push(root);
    q.push(NULL); // this level is completed
    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    root = buildnode(root);
    cout << " level order \n";
    levelordertraversal(root);
    return 0;
}