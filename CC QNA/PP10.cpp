#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int target;
    int value;

    int nums;
    cin >> nums;
    int arr[nums];
    for (int i = 0; i < nums; i++)
    {
        cin >> *(arr + i);
    }
    cin >> target;

    value = target;
    for (int j = 0; j < nums; j++)
    {
        value = target;
        value = value - *(arr + j);
        for (int k = 0; k < nums; k++)
        {
            if (value == *(arr + k))
            {
                cout << "(" << j << " , " << k << ")" << endl;

                return 0;
            }
        }
    }

    return 0;
}