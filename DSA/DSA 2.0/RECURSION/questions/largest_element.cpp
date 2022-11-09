#include <bits/stdc++.h>

using namespace std;
int max = -999999;

int func(int arr[], int size)
{

    static int i = 0;

    if (i < size)
    {

        if (::max < arr[i])
        {
            ::max = arr[i];
            i++;
            func(arr, size);
        }
        else
        {
            i++;
            func(arr, size);
        }
    }
    return ::max;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[10] = {
        12,
        145,
        67,
        456,
        32,
        21,
        434,
        65,
        32,
        212,
    };
    cout << func(arr, 10);
    return 0;
}