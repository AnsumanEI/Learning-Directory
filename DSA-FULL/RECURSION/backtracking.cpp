#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void fun1(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    fun1(n - 1);
}
int main()
{
    fun1(10);
    return 0;
}