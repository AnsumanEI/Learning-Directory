#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class Solution
{

public:
    int hIndex(vector<int> &citations)
    {
        int l = 0;
        int n = citations.size() - 1;
        int r = n;
        int mid = l + (r - l) / 2;
        int h;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            h = n - mid + 1;
            if (citations[mid] == h)
            {
                return h;
            }
            else if (citations[mid] == h - 1)
            {
                return h - 1;
            }
            else if (citations[mid] > h)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return n - l + 1; // check this
    }
};
int main()
{
    Solution obj;
    vector<int> h = {0};
    cout << obj.hIndex(h);
    return 0;
}