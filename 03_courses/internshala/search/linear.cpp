#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int arr[10];
    int target;
    for (int i = 0; i < 10; i++)
    {

        arr[i] = rand() % 20 + 0;
    };
    target = 13;
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == target)
        {
            cout << i << " ";
            cout << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "not found";
    return 0;
}