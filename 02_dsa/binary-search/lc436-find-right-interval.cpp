#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class Solution
{
    // right interval
private:
    int binary_search(vector<pair<pair<int, int>, int>> &sorted, int interval, int n)
    {
        if (sorted[n - 1].first.first < interval)
        {
            return -1;
        }
        int l = 0;
        int r = n - 1;
        int mid = l + (r - l) / 2;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (sorted[mid].first.first >= interval)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return sorted[l].second;
    }

public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<pair<int, int>, int>> sorted;
        int size_interval = intervals.size();
        for (int i = 0; i < size_interval; ++i)
        {
            sorted.push_back({{intervals[i][0], intervals[i][1]}, i});
        }
        sort(sorted.begin(), sorted.end());
        vector<int> results(size_interval, -1);
        for (int i = 0; i < size_interval; ++i)
            results[i] = binary_search(sorted, intervals[i][1], size_interval);
        return results;
    }
};
int main()
{
    Solution a;
    vector<vector<int>> interval = {{1, 3}, {3, 5}, {4, 5}};
    a.findRightInterval(interval);

    return 0;
}