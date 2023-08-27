#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int arr[] = {1, 2, 31, 4, 5, 6, 7, 8, 9, 10};
    int max = arr[0];
    for (int i = 0; i < sizeof(arr) >> 2; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << max << endl;
    return 0;
}