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
    bool pallindrome(string &s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != s[s.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    void solver(string &s, vector<vector<string>> &res, vector<string> &curr, int ind)
    {
        if (ind == s.size())
        {
            res.push_back(curr);
            return;
        }
        for (int i = ind; i < s.size(); i++)
        {
            string text = s.substr(ind, i - ind + 1);
            if (pallindrome(text))
            {
                curr.push_back(text);
                solver(s, res, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> curr;
        solver(s, res, curr, 0);
        return res;
    }
};
int main()
{

    return 0;
}