#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minheap;
        vector<vector<int>> res;
        for (auto &p : points)
        {
            int dist;
            int x = p[0];
            int y = p[1];

            dist = (x * x) + (y * y);

            minheap.push({dist, p});
        }
        int temp = k;

        while (temp != 0)
        {
            res.push_back(minheap.top().second);
            minheap.pop();
            temp--;
        }
        return res;
    }
};
int main()
{

    return 0;
}