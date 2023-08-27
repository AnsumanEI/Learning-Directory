#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) >> 2;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    cout << "the sum is " << sum << endl;

    // while
    int sum1 = 0;
    size--;
    while (size >= 0)
    {
        sum1 += arr[size];
        size--;
    }
    cout << "the sum1 is " << sum1 << endl;
    return 0;
}