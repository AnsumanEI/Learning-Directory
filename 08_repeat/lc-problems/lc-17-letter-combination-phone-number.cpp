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
    void solver(string &digits, unordered_map<char, string> &phn, vector<string> &res, string &curr, int ind)
    {
        if (curr.size() == digits.size())
        {
            res.push_back(curr);
            return;
        }
        for (char &c : phn[digits[ind]])
        {
            curr.push_back(c);
            solver(digits, phn, res, curr, ind + 1);
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
        vector<string> res;
        string curr;
        solver(digits, phn, res, curr, 0);
        return res;
    }
};
int main()
{

    return 0;
}