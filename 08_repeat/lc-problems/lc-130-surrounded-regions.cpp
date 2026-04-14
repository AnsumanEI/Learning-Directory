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
    void bfs(vector<vector<char>> &board, queue<pair<int, int>> &check)
    {
        int rows = board.size();
        int cols = board[0].size();
        while (!check.empty())
        {
            auto [cx, cy] = check.front();
            check.pop();

            if (cx + 1 < rows && board[cx + 1][cy] == 'O')
            {
                check.push({cx + 1, cy});
                board[cx + 1][cy] = 'T';
            }
            if (cx - 1 >= 0 && board[cx - 1][cy] == 'O')
            {
                check.push({cx - 1, cy});
                board[cx - 1][cy] = 'T';
            }
            if (cy + 1 < cols && board[cx][cy + 1] == 'O')
            {
                check.push({cx, cy + 1});
                board[cx][cy + 1] = 'T';
            }
            if (cy - 1 >= 0 && board[cx][cy - 1] == 'O')
            {
                check.push({cx, cy - 1});
                board[cx][cy - 1] = 'T';
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        queue<pair<int, int>> check;
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < cols; i++)
        {
            if (board[0][i] == 'O')
            {
                check.push({0, i});
                board[0][i] = 'T';
            }

            if (board[rows - 1][i] == 'O')
            {
                check.push({rows - 1, i});
                board[rows - 1][i] = 'T';
            }
        }

        for (int i = 0; i < rows; i++)
        {
            if (board[i][0] == 'O')
            {
                check.push({i, 0});
                board[i][0] = 'T';
            }

            if (board[i][cols - 1] == 'O')
            {
                check.push({i, cols - 1});
                board[i][cols - 1] = 'T';
            }
        }

        bfs(board, check);
        for (auto &p : board)
        {
            for (auto &q : p)
            {
                if (q == 'O')
                {
                    q = 'X';
                }
                else if (q == 'T')
                {
                    q = 'O';
                }
            }
        }
    }
};

int main()
{

    return 0;
}