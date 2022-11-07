#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    pair<int, int> p[5];
    p[0] = {1, 2};
    p[1] = {5, 2};
    p[2] = {3, 4};
    p[3] = {2, 9};
    p[4] = {9, 1};
    sort(p, p + 5);
    for (int i = 0; i < 5; i++)
    {
        cout << p[i].first << " " << p[i].second << " :: ";
    }
    return 0;
}