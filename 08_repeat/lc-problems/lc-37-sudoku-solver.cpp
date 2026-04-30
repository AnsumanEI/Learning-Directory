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
    bool solver(vector<vector<char>> &board, unordered_set<int> row[], unordered_set<int> col[], unordered_set<int> box[], int trow, int tcols)
    {
        if (trow == 9)
        {
            return true;
        }
        if (tcols >= 9)
        {
            return solver(board, row, col, box, trow + 1, 0);
        }
        if (board[trow][tcols] != '.')
        {
            return solver(board, row, col, box, trow, tcols + 1);
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if (row[trow].count(i) < 1 && col[tcols].count(i) < 1 && box[(trow / 3) * 3 + tcols / 3].count(i) < 1)
                {
                    row[trow].insert(i);
                    col[tcols].insert(i);
                    box[(trow / 3) * 3 + tcols / 3].insert(i);
                    board[trow][tcols] = i + '0';
                    if (solver(board, row, col, box, trow, tcols + 1))
                        return true;

                    int num = board[trow][tcols] - '0'; // we can use i also but i was confused in backtracking so i used num
                    row[trow].erase(num);
                    col[tcols].erase(num);
                    box[(trow / 3) * 3 + tcols / 3].erase(num);
                    board[trow][tcols] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        unordered_set<int> row[9];
        unordered_set<int> cols[9];
        unordered_set<int> box[9];
        int traverserow;

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] != '.')
                {
                    int num = board[r][c] - '0';
                    row[r].insert(num);
                    cols[c].insert(num);
                    box[(r / 3) * 3 + c / 3].insert(num);
                }
            }
        }
        solver(board, row, cols, box, 0, 0);
    }
};
int main()
{

    return 0;
}