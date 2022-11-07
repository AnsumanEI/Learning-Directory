#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    vector<int> v = {3, 4, 8, 2, 1};
    int a[5] = {3, 4, 8, 2, 1};
    sort(a, a + 5);
    cout << "array :: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "vector :: ";
    sort(v.begin(), v.end());
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}