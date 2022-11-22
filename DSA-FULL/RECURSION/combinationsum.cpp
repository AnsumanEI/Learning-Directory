#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void subsum(int index, vector<int> &ds, int arr[], int n, int target)
{
    if (index == n)
    {
        if (target == 0)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return;
        }
        return;
    }
    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        subsum(index, ds, arr, n, target - arr[index]);
        ds.pop_back();
    }
    subsum(index + 1, ds, arr, n, target);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> ds;
    subsum(0, ds, arr, 5, 7);

    return 0;
}