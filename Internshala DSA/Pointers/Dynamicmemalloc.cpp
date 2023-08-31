#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int *value;
    int n = 5;
    value = (int *)malloc(sizeof(int) * n);
    // or
    int *value1 = new int[10]; // same as malloc
    // realloc
    n = 10;
    value = (int *)realloc(value, sizeof(int) * n);
    return 0;
}