#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int hold1, sold1, hold2, sold2;

        // day 0 buying and selling , initialisation
        hold1 = 0 - prices[0];
        sold1 = 0;
        hold2 = 0 - prices[0];
        sold2 = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            int price = prices[i];
            hold1 = max(hold1, 0 - price);
            sold1 = max(sold1, hold1 + price);
            hold2 = max(hold2, sold1 - price);
            sold2 = max(sold2, hold2 + price);
        }

        return sold2;
    }
};
int main()
{

    return 0;
}