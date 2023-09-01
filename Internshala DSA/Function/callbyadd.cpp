#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void swap(int *a, int *b)
{
    // call by address
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a = 10, b = 20;
    swap(&a, &b);          // call by address
    cout << a << " " << b; // call by address makes the element editable in the function
    // call  by value is default calling

    return 0;
}