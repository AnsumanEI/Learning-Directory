#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>

using namespace std;
void reverse(int i, int arr[], int n)
{
    if (i >= n / 2)
    {
        return;
    }
    else
    {
        swap(arr[i], arr[n - i - 1]);
        reverse(i + 1, arr, n);
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    reverse(0, arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}