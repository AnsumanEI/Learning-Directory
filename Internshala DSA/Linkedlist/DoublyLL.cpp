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
    node *prev;
    node *next;
    // constructor
    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
node *head;
node *tail;
void printf(node *&head)
{
    node *temp = head;
    cout << "\n";
    while (temp != NULL)
    {
        cout << "<---[" << temp->data << "]"
             << "--->";
        temp = temp->next;
    }
}
int getlength(node *head)
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
void newathead(node *&head, int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void newattail(node *&tail, int data)
{
    node *temp = new node(data);
    if (tail == NULL)
    {
        head == temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void newatpos(int pos, int data)
{
    node *temp = head;
    if (pos == 1)
    {
        newathead(head, data);
        return;
    }
    int headpos = 1; // 1st node head
    while (headpos < pos - 1)
    {
        temp = temp->next;
        headpos++;
    }
    if (temp->next == NULL) // insert at last
    {
        newattail(tail, data);
        return;
    }
    node *toinsert = new node(data);
    toinsert->next = temp->next;
    temp->prev = toinsert;
    temp->next = toinsert;
    toinsert->prev = temp;
}
int main()
{
    node *one = new node(10);
    head = one;
    tail = one;
    newathead(head, 20);
    newathead(head, 30);
    newathead(head, 40);

    newattail(tail, 20);
    newattail(tail, 30);
    newattail(tail, 40);

    printf(head);

    newatpos(1, 999);
    newatpos(3, 999);
    newatpos(10, 999);
    printf(head);
    cout << " \n length ::" << getlength(head);
    return 0;
}