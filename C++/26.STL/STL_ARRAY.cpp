#include <bits/stdc++.h>
#include <array>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    array<int, 5> arr = {1, 2, 3, 4, 5};
    array<int, 5> arr2;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << arr.at(3) << " at " << endl;
    cout << arr.front() << " front " << endl;
    cout << arr.back() << " back " << endl;
    cout << arr.empty() << " empty or not " << endl;
    arr.fill(1); // fills 10 at every postion in the array
    arr2.fill(2);
    cout << *arr.data() << " returns the pointer to the 1st element " << endl;
    arr.swap(arr2); // swaps array 1 with array 2 should of same size
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    cout << arr.max_size() << endl; // capacity of the array
    return 0;
}