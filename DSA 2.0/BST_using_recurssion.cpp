#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int num, int start, int end)
{
    int mid;

    if (start > end)
    {

        cout << "number not present";
        return 0;
    }
    else
    {

        mid = (start + end) / 2;

        if (arr[mid] == num)
        {

            cout << "address :: " << mid << " index \n";
            return 0;
        }
        else if (num > arr[mid])
        {

            BinarySearch(arr, num, mid + 1, end);
        }
        else if (num < arr[mid])
        {

            BinarySearch(arr, num, start, mid - 1);
        }
    }
}

int main()
{

    int arr[100], key, i, size, start, end;

    cout << "Enter the size \n";
    cin >> size;

    cout << "Enter  values \n";

    for (i = 0; i < size; i++)
    {

        cin >> arr[i];
    }
    sort(arr, arr + size);
    cout << "Enter a value to be search \n";
    cin >> key;

    start = 0;
    end = size - 1;

    BinarySearch(arr, key, start, end);

    return 0;
}