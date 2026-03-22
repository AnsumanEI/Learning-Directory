#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void sub(int index, vector<int> &ds, int arr[], int n)
{
    if (index >= n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // take condition
    ds.push_back(arr[index]);
    sub(index + 1, ds, arr, n);
    ds.pop_back();
    // not take condition
    sub(index + 1, ds, arr, n);
}
int main()
{
    // sub array but with sequence maintained is called sub seqence
    int arr[] = {3, 1, 2};
    vector<int> ds;
    sub(0, ds, arr, 3);
    return 0;
}