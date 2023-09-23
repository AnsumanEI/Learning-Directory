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
    // constructor

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
            next = NULL;
        }
        cout << "\n memory freed for " << value << "\n";
    }
};
node *tail; // only tail used in circular ll
void insert(int data, int prevdata)
{
    // for empty LL
    if (tail == NULL)
    {
        node *temp = new node(data);
        temp->next = temp;
        tail = temp;
    }
    else
    {
        // non empty list
        // assuming the prevdata given is present in ll
        node *current = tail;
        while (current->data != prevdata)
        {
            current = current->next;
        }
        node *temp1 = new node(data);
        temp1->next = current->next;
        current->next = temp1;
    }
}
void print(node *tail)
{
    node *temp = tail;
    if (tail == NULL)
    {
        cout << " \n empty \n";
        return;
    }
    do
    {
        cout << "<---[" << tail->data << "]--->";
        tail = tail->next;
    } while (tail != temp);
}
void deletenode(node *&tail, int datatodel)
{
    if (tail == NULL)
    {
        cout << "\n already empty \n ";
        return;
    }
    else
    {
        node *prev = tail;
        node *current = prev->next;
        if (current == prev) // one node ll
        {
            tail = NULL;
        }
        while (current->data != datatodel)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        if (tail == current)
        {
            tail = prev->next;
        }
        current->next = NULL;
        delete current;
    }
}
int main()
{

    insert(11, 10);
    insert(12, 11);
    insert(13, 12);
    insert(14, 13);
    insert(15, 14);
    deletenode(tail, 11);
    print(tail);
    return 0;
}