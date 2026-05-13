#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> store;

        for (auto &p : s)
        {
            freq[p]++;
        }
        for (auto &p : freq)
        {
            store.push({p.second, p.first});
        }
        string res;
        while (!store.empty())
        {
            pair<int, char> temp = store.top();
            store.pop();
            while (temp.first != 0)
            {
                res.push_back(temp.second);
                temp.first--;
            }
        }
        return res;
    }
};
int main()
{

    return 0;
}