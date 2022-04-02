#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr;
    int element;
    cin >> element;

    while (element--)
    {
        int elements;
        cin >> elements;
        arr.push_back(elements);
    }

    int a = 0;
    cin >> a;
    arr.erase(arr.begin() + a);
    int b;
    cin >> a;
    cin >> b;
    int count = b - a;

    while (count--)
    {
        arr.erase(arr.begin() + a);
        a++;
    }
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}