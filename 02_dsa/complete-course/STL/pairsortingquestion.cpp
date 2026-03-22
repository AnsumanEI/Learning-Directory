#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    // print name of the students on the decreasing order of their marks
    pair<int, string> list[5];
    list[0] = {49, "ansuman"};
    list[1] = {23, "gg1"};
    list[2] = {35, "helloworld"};
    list[3] = {50, "sw"};
    list[4] = {10, "gg2"};

    sort(list, list + 5);
    int count = 1;

    for (int i = 4; i >= 0; i--)
    {
        cout << "rank-> " << count << " marks -> " << list[i].first << " name -> " << list[i].second << endl;
        count++;
    }
    return 0;
}