#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
static bool create = false;
class node
{
public:
    int data;
    node *prev;
    node *next;
    // constructor
    node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    // destructor
    ~node()
    {
        int value = this->data;
        while (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "\t\t\n Memory Freed for Value ::\n " << value;
    }
};

node *head;
node *tail;
node *one;
void createnode(int data = 0)
{
    one = new node(data);
    head = one;
    tail = one;
    create = false;
}
void insertathead(int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    temp->prev = NULL;
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void insertattail(int data)
{
    node *temp = new node(data);
    if (tail == NULL)
    {
        head = temp;
        tail == temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insert(int data, int pos)
{
    node *temp = head;
    if (pos == 1)
    {
        insertathead(data);
        return;
    }
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *insert = new node(data);
    insert->next = temp->next;
    temp->next = insert;
    temp->next->prev = insert;
    insert->prev = temp;
}
void deletenode(int pos)
{
    node *temp = head;
    if (pos == 1)
    {
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        int count = 1;
        node *current = head;
        node *prev = NULL;
        while (count < pos)
        {
            prev = current;
            current = current->next;
            count++;
        }
        if (current->next == NULL)
        {
            tail = prev;
        }
        prev->next = current->next;
        current->prev = NULL;
        current->next = NULL;
        delete current;
    }
}
void printll(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << "<---[" << temp->data << "]"
             << "--->";
        temp = temp->next;
    }
}
int lengthofll()
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    createnode(10);
    insertathead(1);
    insertattail(100);
    insert(99, 4);
    printll(head);
    return 0;
}