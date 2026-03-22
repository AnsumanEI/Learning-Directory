#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int sum;
int small;
void second()
{
    cout << ::small << endl;
}
void first(int a, int b, int c)
{
    ::sum = (a + b + c) / 3;
    if (a < b && a < c)
        ::small = a;
    else if (b < c)
        ::small = b;
    else
        ::small = c;

    second();
}

int main()
{
    first(50, 200, 30);
    return 0;
}