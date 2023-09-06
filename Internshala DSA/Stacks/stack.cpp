#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
#define SIZE 10
using namespace std;
typedef struct main_stack
{
    int arr_max[SIZE];
    int top = -1;
} node;
void push(struct main_stack *node, int num)
{
    if (node->top == -1)
        node->top = 0;
    else if (node->top == SIZE)
    {
        cout << "OVERFLOW" << endl;
        node->top = -1;
    }
    node->arr_max[node->top];
    node->top += 1;
}
int pop(struct main_stack *node)
{
    if (node->top == -1)
    {
        cout << "UNDERFLOW" << endl;
    }
    int temp = node->arr_max[node->top];
    node->top += 1;
    return temp;
}
void display(struct main_stack *node)
{
    cout << "THE STACK -> " << endl;
    for (int i = 0; i < node->top; i++)
    {
        cout << node->arr_max[i] << endl;
    }
}
int main()
{
    struct main_stack one;

    int close = 1;
main:
    cout << " FOR PUSH PRESS 1 \n FOR POP PRESS 2 \n FOR DISPLAY PRESS 3 \n TO CLOSE PRESS 4 " << endl;

    int ch;
    cin >> ch;
    while (close == 1)
    {
        switch (ch)
        {
        case 1:
            cout << "enter the element : ";
            int item;
            cin >> item;
            push(&one, item);
            goto main;
            break;
        case 2:
            cout << "popped number -> " << pop(&one);
            goto main;
            break;
        case 3:
            display(&one);
            goto main;
            break;
        case 4:
            close = 0;
        default:
            break;
        }
    }
    return 0;
}