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

void createnode(int data)
{
    node *one = new node(data);
    head = one;
    create = false;
}
void insertathead(node *&head, int data)
{
    node *temp = new node(data);
    temp->prev = NULL;
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void insertattail(int data) {}
void insert(int data) {}
void shownode() {}
void deletenode(int pos) {}
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
void lengthofll() {}

int main()
{

    insertathead(head, 1);
    printll(head);
    return 0;
}