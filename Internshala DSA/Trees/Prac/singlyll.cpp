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
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
            cout << "memory freed for " << value;
            cout << endl;
        }
    }
};
node *head;
node *tail;
ostream &operator<<(ostream &o, node *&one)
{
    o << one->data << " ";
    return o;
}
void printll(node *head)
{
    while (head != NULL)
    {
        cout << head;
        head = head->next;
    }
}
void insertathead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void insertattail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
void insertatpos(int pos, int data)
{
    if (pos == 1)
    {
        insertathead(head, data);
        return;
    }
    else
    {
        int headpos = 1;
        node *neww = new node(data);
        node *temp = head;
        while (headpos < pos - 1)
        {
            temp = temp->next;
            headpos++;
        }
        if (temp->next == NULL)
        {
            insertattail(tail, data);
            return;
        }
        neww->next = temp->next;
        temp->next = neww;
    }
}
void deletepos(node *&head, int pos)
{
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *current = head;
        node *prev = NULL;
        int headpos = 1;
        while (headpos < pos)
        {
            prev = current;
            current = current->next;
            headpos++;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}
int main()
{
    node *one;
    one = new node(1);
    head = tail = one;
    insertathead(head, 2);
    insertatpos(1, 3);
    deletepos(head, 1);
    printll(head);
    return 0;
}