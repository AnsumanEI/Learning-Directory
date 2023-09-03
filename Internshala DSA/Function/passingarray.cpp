#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void arrplus(int *arr) // or int arr[]
{
    cout << arr << " " << *arr << endl;
    *(arr + 1) += 1;
}
int main()
{
    int arr[3] = {1, 1, 3};
    arrplus(arr);
    cout << arr[1];
    return 0;
}