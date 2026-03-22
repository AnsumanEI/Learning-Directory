#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i = 0;
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int songs;
        int johnny = 0;
        int key;
        cin >> songs;
        int list[songs];
        for (i = 0; i < songs; i++)
        {
            cin >> *(list + i);
        }
        cin >> key;
        johnny = list[key - 1];
        sort(list, list + songs);
        for (i = 0; i < songs; i++)
        {
            cout << *(list + i);
        }
        for (i = 0; i < songs; i++)
        {
            if (johnny == list[i])
            {
                johnny = i;
            }
        }
        cout << johnny + 1 << endl;
    }
    return 0;
}