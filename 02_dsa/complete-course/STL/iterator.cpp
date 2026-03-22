#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    // pointers and iterators behave like the same
    vector<int> v = {1, 2, 3, 4, 5};
    int a[5] = {1, 2, 3, 4, 5};
    // vector<int>::iterator it = v.begin();
    auto it = v.begin();
    cout << *it << " ";
    cout << *++it << " ";
    int *p = a;
    cout << endl;
    cout << *p << " ";
    cout << *++p << " ";
    return 0;
}