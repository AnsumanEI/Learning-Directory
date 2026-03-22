#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int m;
    cin >> m;
    map<string, int> name;
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        if (name[s] == 0)
        {
            cout << "OK";
        }
        else
        {
            cout << s << name[s] << endl;
        }
        name[s]++;
    }
    return 0;
}