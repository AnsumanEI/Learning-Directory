#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    // for any number there are two parts part of factor one is befor root n and another part after root n
    // for eg 18 before root n (root 18 = 4.something) so before 4 we get 1 , 2 , 3
    // so the total number of factors will be 6 as after root n will be the same n/1,2,3 which are 18 , 9 , 6
    // so this will run in o(root n) which is faster than o(n)
    // i*n/i = n
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0 && i != (n / i))
        {
            count += 2;
        }
    }
    cout << count << endl;
    if (count == 2)
    {
        cout << "prime" << endl;
    }
    else
    {
        cout << "not prime" << endl;
    }
    return 0;
}