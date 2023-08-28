#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    vector<pair<pair<int, int>, int>> hello;
    vector<vector<int>> interval;
    interval.push_back({2, 1});
    interval.push_back({3, 2});
    interval.push_back({4, 3});
    int n = hello.size();

    hello.push_back({{interval[0][1], interval[1][1]}, n});
}