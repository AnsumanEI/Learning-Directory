#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    // gap can be taken anything optimal mostly we use n/2
    int size;
    cout << "enter the size of the array ";
    cin >> size;
    int arr[size];
    for (auto &x : arr)
    {
        cout << "ENTER ";
        cin >> x;
    }
    for (auto &x : arr)
    {
        cout << x << endl;
    }

    return 0;
}