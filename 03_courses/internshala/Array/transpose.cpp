#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int *transpose(int arr[][3])
{
    static int arr1[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr1[i][j] = arr[j][i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    return *arr1;
};
int main()
{
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int *ans = transpose(arr);
    for (int i = 0; i < 9; i++)
    {

        if ((i + 1) % 3 == 0)
            cout << *ans + i << " ";
        }

    return 0;
}