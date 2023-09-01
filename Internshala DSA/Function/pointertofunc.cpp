#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void first()
{
    cout << "first" << endl;
}
void second()
{
    cout << "second" << endl;
}
void third()
{
    cout << "third" << endl;
}
int main()
{
    void (*ptr)();
    ptr = first;
    (*ptr)();
    ptr = second;
    (*ptr)();
    ptr = third;
    (*ptr)();
    return 0;
}