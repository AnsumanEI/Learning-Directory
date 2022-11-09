#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int bst(int arr[], int key, int begin, int end)
{
    int mid;

    if (begin > end)
    {
        cout << "not present" << endl;
        return 0;
    }

    else
    {
        mid = (begin + end) / 2;
        if (arr[mid] == key)
        {
            return mid + 1;
        }
        else if (arr[mid] > key)
        {
            mid -= 1;
            bst(arr, key, begin, mid);
        }
        else
        {
            mid += 1;
            bst(arr, key, mid, end);
        }
    }
}

int main()
{
    int size;
    cout << "enter the size ::";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "enter element " << i + 1 << endl;
        cin >> arr[i];
    }
    sort(arr, arr + size);
    int key;
    cout << endl;
    cout << "enter the key" << endl;
    cin >> key;
    int begin;
    int end;
    begin = 0;
    end = size - 1;
    cout << "address is ::";
    cout << bst(arr, key, begin, end);
}