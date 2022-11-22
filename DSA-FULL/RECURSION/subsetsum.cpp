#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void subsum(int index, vector<int> &sumsub, int arr[], int sum, int n)
{
    if (index >= n)
    {
        sumsub.push_back(sum);
        return;
    }
    // take
    subsum(index + 1, sumsub, arr, sum + arr[index], n);
    // not take
    subsum(index + 1, sumsub, arr, sum, n);
}
int main()
{
    int arr[] = {3, 1, 2};
    vector<int> sum;
    subsum(0, sum, arr, 0, 3);
    sort(sum.begin(), sum.end());
    for (auto it : sum)
    {
        cout << it << " ";
        cout << endl;
    }
    return 0;
}