#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class solution
{
public:
    bool issafe()
    {
    }
    void combination(vector<vector<string>> &ans, vector<string> &board, int n)
    {
    }
    vector<vector<string>> helper(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        combination(ans, board, n);
    }
};
int main()
{

    return 0;
}