#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // 0 day preparation
        vector<int> hold(k, 0 - prices[0]);
        vector<int> sold(k, 0);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                int prevcash = j == 0 ? 0 : sold[j - 1]; // for hold j to but we need cash from prev day

                hold[j] = max(hold[j], prevcash - prices[i]);
                sold[j] = max(sold[j], hold[j] + prices[i]);
            }
        }
        return sold[k - 1]; // k-1 because for k trans we go from 0 to k-1
    }
};
int main()
{

    return 0;
}