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
    node *nextlink;
    // default constructor
    node(int data = 0)
    {
        this->data = data;
        this->nextlink = NULL;
    }
};
node *head;
node *tail;
ostream &operator<<(ostream &o, node &one)
{
    o << "Data =" << one.data << endl;
    return o;
}
void printll(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << "[" << temp->data << "]"
             << "---->";
        temp = temp->nextlink; // next address
    }
}
void newhead(node *&head, int data)
{
    //&head is used as nextlink stores address of the next node so * to hold address of &head
    // new node create
    node *temp = new node(data);
    // new node created will point to head instead of null
    temp->nextlink = head;
    // temp is address (pointer type)
    head = temp;
}
void newafter(node *&tail, int data)
{
    node *temp = new node(data);
    tail->nextlink = temp;
    temp->nextlink = NULL;
    tail = temp;
}
void newatpos(int pos, int data)
{
    node *temp = head;
    if (pos == 1) // for entering in the beginning
    {
        newhead(head, data);
        return;
    }
    int headpos = 1; // 1st node head
    while (headpos < pos - 1)
    {
        temp = temp->nextlink;
        headpos++;
    }
    if (temp->nextlink == NULL) // insert at last
    {
        newafter(tail, data);
        return;
    }
    // new node;
    node *toinsert = new node(data);
    toinsert->nextlink = temp->nextlink;
    temp->nextlink = toinsert;
}
int main()
{
    node *one = new node(10);
    head = one; // head is declared above to get used in newatpos function
    tail = one;
    //  cout << *one; // to print particular node
    newhead(head, 20); // if we directly give one hear the main node will update as we are passing refrences
    newhead(head, 30);
    newhead(head, 40);
    newafter(tail, 30);
    newatpos(1, 50); // testing head
    newatpos(6, 20); // testing middle
    newatpos(8, 40); // testing tail
    cout << *head;   // testign head after inserting from head
    cout << *tail;   // testing tail postn after insertion in tail
    printll(head);
    return 0;
}