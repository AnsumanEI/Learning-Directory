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
    void solver(vector<string> &grid, int row, unordered_set<int> &col, unordered_set<int> &diag1, unordered_set<int> &diag2, vector<vector<string>> &res, int &n)
    {
        if (row == n)
        {
            res.push_back(grid);
            return;
        }
        for (int c = 0; c < n; c++)
        {
            if (col.count(c) || diag1.count(row - c) || diag2.count(row + c))
            {
                continue;
            }

            grid[row][c] = 'Q';
            col.insert(c);
            diag1.insert(row - c);
            diag2.insert(row + c);

            solver(grid, row + 1, col, diag1, diag2, res, n);

            grid[row][c] = '.';
            col.erase(c);
            diag1.erase(row - c);
            diag2.erase(row + c);
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        int row = 0;
        unordered_set<int> col, diag1, diag2;
        solver(board, row, col, diag1, diag2, res, n);
        return res;
    }
};
int main()
{

    return 0;
}