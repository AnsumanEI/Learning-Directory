#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <windows.h>
#include <cstring>
#define size 5
using namespace std;
struct store
{
    int front = -1;
    int rear = -1;
    int arr[size];
};
store qu[10];
void enqueue(struct store *one, int item)
{
    if (one->front == 0 && one->rear == size - 1 || one->front == one->rear + 1)
    {
        cout << "overflow ";
    }

    if (one->front == -1)
    {
        one->front = 0;
        one->rear = 0;
    }
    else if (one->rear = size - 1)
    {
        one->rear = 0;
    }
    one->arr[one->rear] = item;
    one->rear++;
}

int dequeue(struct store *one)
{
    if (one->front <= -1)
    {
        cout << "underflow";
        getchar();
    }
    int val = one->arr[one->front];
    if (one->front == one->rear)
    {
        one->front = -1;
        one->rear = -1;
    }
    else if (one->front == size - 1)
    {
        one->front = 0;
    }
    else
    {
        one->front--;
    }
    return val;
}
void display(struct store *one)
{
    cout << "THE Queue -> " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << one->arr[i] << endl;
    }
}

int main()
{

    struct store one;
main:
    system("cls");
    cout << " FOR PUSH PRESS 1 \n FOR POP PRESS 2 \n FOR DISPLAY PRESS 3 \n TO CLOSE PRESS 4 " << endl;
    int ch;
    cin >> ch;
    while (1)
    {
        switch (ch)
        {
        case 1:
            cout << "enter the element : ";
            int item;
            cin >> item;
            enqueue(&one, item);
            goto main;
            break;
        case 2:
            cout << "popped element - >" << dequeue(&one);
            Sleep(1500);
            goto main;
            break;
        case 3:
            display(&one);
            getchar();
            goto main;
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}