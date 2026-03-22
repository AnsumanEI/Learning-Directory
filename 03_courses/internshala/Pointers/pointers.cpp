#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    // normal ptr
    int *ptr;
    int a = 100;
    ptr = &a;
    cout << ptr << " " << *ptr << &ptr << endl;
    // pointer to pointer
    int **ptt;
    ptt = &ptr;
    cout << ptt << *ptt << **ptt << &ptt << endl;

    return 0;
}