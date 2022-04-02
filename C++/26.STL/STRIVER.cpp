#include <bits/stdc++.h>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    array<int, 10> arr;
    arr.fill(10);
    array<int, 10> arr1(arr);
    arr1.at(0) = 9;
    for (auto i : arr1)
    {
        cout << i << " ";
    }

    return 0;
}