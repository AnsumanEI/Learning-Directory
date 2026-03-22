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
    int cases;
    cin >> cases;
    while (cases--)
    {
        int size;
        cin >> size;
        int array[size];
        for (int i = 0; i < size; i++)
        {
            cin >> *(array + i);
        }
        sort(array, array + size);
        cout << array[0] + array[1] << endl;
    }
    return 0;
}