#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<string> &res, unordered_map<char, string> &phn, string &digits, string &curr, int ind)
    {
        if (curr.size() == digits.size())
        {
            res.push_back(curr);
            return;
        }
        for (auto &p : phn[digits[ind]])
        {
            curr.push_back(p);
            dfs(res, phn, digits, curr, ind + 1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> phn;
        phn['2'] = {"abc"};
        phn['3'] = {"def"};
        phn['4'] = {"ghi"};
        phn['5'] = {"jkl"};
        phn['6'] = {"mno"};
        phn['7'] = {"pqrs"};
        phn['8'] = {"tuv"};
        phn['9'] = {"wxyz"};
        vector<string> result;
        string curr;
        if (digits.empty())
        {
            return {};
        }
        dfs(result, phn, digits, curr, 0);
        return result;
    }
};

int main()
{

    return 0;
}