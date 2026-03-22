#include <bits/stdc++.h>
using namespace std;
int insert(int address, int value, int *arr, int size)
{

    for (int i = size; i > address; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[address] = value;
}

int main()
{
    // array insert function
    int size;
    cin >> size;
    int arr[size + 1];

    for (int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }

    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }

    insert(5, 10, &arr[0], size);
    return 0;
}