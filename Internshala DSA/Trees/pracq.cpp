#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
// make class for tree building
// show height
// check balanced or not
// show diameter of tree
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
void displaytree(node *root)
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
pair<int, int> diafast(node *root);
int getdiameter(node *root)
{
    // if (root == NULL)
    // {
    //     return 0;
    // }
    // int op1 = getdiameter(root->left);
    // int op2 = getdiameter(root->right);
    // int op3 = getheight(root->left) + 1 + getheight(root->right);
    // int ans = max(op1,max(op2,op3));
    // return ans ;
    return diafast(root).first;
}
pair<int, int> diafast(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = {0, 0};
        return p;
    } // left int is diameter right int is height int he pair
    pair<int, int> left = diafast(root->left);
    pair<int, int> right = diafast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
pair<bool, int> isbalanced(node *root);
bool isbalance(node *root)
{
    return isbalanced(root).first;
    // brute force
    // if (root == NULL)
    // {
    //     return true;
    // }
    // bool left = isbalance(root->left);
    // bool right = isbalance(root->right);
    // bool diff = abs(getheight(root->left) - getheight(root->right) <= 1);
    // if(left&&right&&diff)
    // {
    //     return true;
    // }
    // else {
    //     return false;
    // }
}
pair<bool, int> isbalanced(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = {true, 0};
        return p;
    }
    pair<bool, int> left1 = isbalanced(root->left);
    pair<bool, int> right1 = isbalanced(root->right);

    bool left = left1.first;
    bool right = right1.first;
    bool diff = abs(left1.second - right1.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left1.second, right1.second) + 1;

    if (left && right && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
int main()
{ // 1 2 3 4 5 6 99 -1 -1 -1 -1 7 -1 -1 -1 -1 -1
    node *root = NULL;
    buildtree(root);
    system("CLS");
    displaytree(root);
    cout << "height ->" << getheight(root);
    cout << endl;
    cout << "diameter ->" << getdiameter(root);
    cout << endl;
    cout << "is balanced ->" << isbalance(root);
    return 0;
}