#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b)
             {
            if ( a[0] == b[0])//if width is same  descending
            {
                return a[1] > b[1];
            }
            return a[0] < b[0] ; }); // ascending

        vector<int> tail;
        tail.push_back(envelopes[0][1]);

        for (int i = 1; i < envelopes.size(); i++)
        {
            int height = envelopes[i][1];

            auto it = lower_bound(tail.begin(), tail.end(), height);
            if (it == tail.end())
            {
                tail.push_back(height);
            }
            else
            {
                *it = height;
            }
        }
        return tail.size();
    }
};
// another way is
struct compare
{
    bool operator()(auto &a, auto &b)
    {
        if (a[0] == b[0]) // if width is same  descending
        {
            return a[1] > b[1];
        }
        return a[0] < b[0]
    }; // ascending
}; // sort ( envelope.begin() , envelope.end() , compare());
int main()
{

    return 0;
}