#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int r = 4, r1 = 3, c = 3, c1 = 4;
    int a[r][c];
    int b[r1][c1];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << i << j << endl;
            cin >> a[i][j];
            cout << endl;
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << i << j << endl;
            cin >> b[i][j];
            cout << endl;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {

            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {

            cout << setw(4) << b[i][j];
        }
        cout << endl;
    }

    // multiplication
    if (c == r1)
    {
        int m[r][c1];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                m[i][j] = 0;
                for (int k = 0; k < r1; k++)
                {
                    m[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        cout << endl;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c1; j++)
            {

                cout << setw(4) << m[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}