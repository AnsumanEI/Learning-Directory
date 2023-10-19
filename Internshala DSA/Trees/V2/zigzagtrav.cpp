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
int main()
{ // 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1
    node *root = NULL;
    buildtree(root);
    system("CLS");
    display(root);
    zigzag(root);
    return 0;
}