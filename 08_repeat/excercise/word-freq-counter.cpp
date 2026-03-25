#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    vector<string> nums = {"apple", "banana", "apple", "cherry", "banana", "apple"};

    unordered_map<string, int> counter;
    for (int i = 0; i < nums.size(); i++)
    {
        if (counter.find(nums[i]) != counter.end())
        {
            counter[nums[i]]++;
        }
        else
        {
            counter[nums[i]] = 1;
        }
    }
    for (auto &value : counter)
    {
        cout << value.first << ": " << value.second;
        cout << endl;
    }

    return 0;
}