#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int cnt_div(int number)
{
    int count = 0;
    int i;
    for (i = 1; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            count++;
            if (i != (number / i))
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int count = cnt_div(i);
        if (count == 2)
        {
            cout << i << " is prime :: " << count << endl;
        }
        else
        {
            cout << i << " not prime :: " << count << endl;
        }
    }
    // this is not optimised as lot of iterations are wasted for eg 49 we check for 4 5 which are wasted iterations
    return 0;
}