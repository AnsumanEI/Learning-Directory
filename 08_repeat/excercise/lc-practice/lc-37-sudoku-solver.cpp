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
    bool solver(vector<vector<char>> &board, unordered_set<int> rowset[], unordered_set<int> colset[], unordered_set<int> boxset[], int row, int col)
    {
        if (row == 9)
        {
            return true;
        }
        if (col == 9)
        {
            return solver(board, rowset, colset, boxset, row + 1, 0);
        }
        if (board[row][col] != '.')
        {
            return solver(board, rowset, colset, boxset, row, col + 1);
        }
        else if (board[row][col] == '.')
        {
            for (int i = 1; i <= 9; i++)
            {
                if (rowset[row].count(i) < 1 && colset[col].count(i) < 1 && boxset[(row / 3) * 3 + col / 3].count(i) < 1)
                {
                    board[row][col] = i + '0';
                    rowset[row].insert(i);
                    colset[col].insert(i);
                    boxset[(row / 3) * 3 + col / 3].insert(i);

                    if (solver(board, rowset, colset, boxset, row, col + 1))
                    {
                        return true;
                    }
                    rowset[row].erase(i);
                    colset[col].erase(i);
                    boxset[(row / 3) * 3 + col / 3].erase(i);
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        unordered_set<int> row[9];
        unordered_set<int> col[9];
        unordered_set<int> box[9];

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] != '.')
                {
                    row[r].insert(board[r][c]);
                    col[c].insert(board[r][c]);
                    box[(r / 3) * 3 + c / 3].insert(board[r][c]);
                }
            }
        }
        solver(board, row, col, box, 0, 0);
    }
};
int main()
{

    return 0;
}