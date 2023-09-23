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

void insertathead(int data)
{
    node *temp = new node(data);
};
void insertattail(int data){};
void insert(int data){};
void shownode(){};
void deletenode(int pos){};
void printll(){};
void lengthofll(){};

void insert int main()
{

    return 0;
}