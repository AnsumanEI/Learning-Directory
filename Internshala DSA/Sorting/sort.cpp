#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
#include <random>
using namespace std;
class solution
{
public:
    vector<int> linearsearch(vector<int> &arr, int size);
};
vector<int> solution::linearsearch(vector<int> &arr, int size)
{
}
int main()
{

    srand(time(0));
    int size = rand() % 10000 + 100;
    vector<int> arr;
    for (int i = 0; i < size; i++)
    {

        int num = rand() % 1000 + 100;
        arr.push_back(num);
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr.at(i) << " ";
    }
    solution obj1;
    obj1.linearsearch(arr, size);
    return 0;
}