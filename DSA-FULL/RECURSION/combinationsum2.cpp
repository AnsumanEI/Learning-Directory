#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void subsum(int index, vector<int> &ds, int arr[], int n, int target)
{
    int i = 0;
    if (index == n)
    {
        if (target == 0)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    if (arr[index] <= target && arr[index] != arr[index + 1])
    {
        ds.push_back(arr[index]);
        // cout << arr[index] << " index ";
        subsum(index + 1, ds, arr, n, target - arr[index]); // index plus 1 as same number cannot be used twice
        ds.pop_back();
    }
    subsum(index + 1, ds, arr, n, target);
}
int main()
{
    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    sort(&arr[0], &arr[7]);
    vector<int> ds;
    subsum(0, ds, arr, 7, 8);

    return 0;
}