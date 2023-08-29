#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int binarysearch(vector<int> &arr, int target)
{
    int l = 0;
    int r = arr.size() - 1;

    int mid = l + (r - l) / 2;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l + 1;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sort(arr.begin(), arr.end());
    int target = 6;
    int ans = binarysearch(arr, target);
    cout << ans;
    return 0;
}