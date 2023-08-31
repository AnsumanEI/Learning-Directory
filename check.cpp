#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class Solution
{
private:
    int binarysearch(vector<int> &missing, int kth)
    {
    }

public:
    int findKthPositive(vector<int> &arr, int k)
    {
        vector<int> missing;
        for (int i = 1; i <= arr.size(); i++)
        {
            for (int j = 1; j < arr.size(); j++)
            {
                
                if (arr[i - 1] != j)
                {
                   
                }
            }
        }
    }
};
int main()
{
    Solution a;
    vector<int> arr = {1, 3, 4, 5, 9, 11};
    a.findKthPositive(arr, 6);
    return 0;
}