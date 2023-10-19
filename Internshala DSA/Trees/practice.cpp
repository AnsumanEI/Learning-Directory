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
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
// build with rec
// build with level order traversal
// display level order
// display in order , pre order , post order
// find diameter , height , balanced
// check if its a sum tree or not
// compare two trees
node *buildwithrec(node *&root)
{
    int data;
    cout << "enter data ";
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "left " << data << endl;
    root->left = buildwithrec(root->left);

    cout << "right" << data << endl;
    root->right = buildwithrec(root->right);
    return root;
}
void buildwithlevelorder(node *&root)
{
    queue<node *> q;
    int data;
    cout << "enter data : ";
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "enter left of " << temp->data;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "enter right of " << temp->data;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
void displaylevelorder(node *root)
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
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    inorder(root->left);

    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);

    inorder(root->right);
    cout << root->data << " ";
}

int findheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = findheight(root->left);
    int right = findheight(root->right);

    int ans = max(left, right) + 1;
    return ans;
}
pair<int, int> finddiameter(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = finddiameter(root->left);
    pair<int, int> right = finddiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int main()
{
    node *root = NULL;
    // buildwithlevelorder(root);
    buildwithrec(root);
    system("CLS");
    displaylevelorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    cout << "height :" << findheight(root);
    cout << endl;
    cout << " diameter :" << finddiameter(root).first;
    cout << endl;
}