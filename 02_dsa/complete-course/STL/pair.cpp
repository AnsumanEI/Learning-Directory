#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
pair<int, string> multiple()
{
    return {18, "ansuman"};
}
int main()
{
    // way to create composite data type
    pair<int, int> p1 = {1, 10};
    pair<int, string> p2 = {2, "strings"};
    pair<int, pair<int, string>> p3 = {2, {2, "bye"}};
    cout << p1.second << endl;
    p1.second = 11;
    // can be usefull in returning multiple value from a function
    cout << multiple().first << " " << multiple().second << " ";
    return 0;
}