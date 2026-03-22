#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void func(int *a, int *b)
{
    cout << a << " " << b;
    cout << endl;
    cout << *a << " " << *b;
    *a += 100;
    *b += 100;
}
int main()
{
    int a;
    int b;
    a = 100;
    b = 200;
    func(&a, &b);
    cout << endl;
    func(&a, &b);
    return 0;
}