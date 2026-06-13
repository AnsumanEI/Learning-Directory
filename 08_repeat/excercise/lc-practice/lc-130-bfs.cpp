#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.empty() || board[0].empty())
            return;

        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> tasks;

        for (int i = 0; i < rows; i++)
        {
            if (board[i][0] == 'O')
            {
                tasks.push({i, 0});
            }
            if (board[i][cols - 1] == 'O')
            {
                tasks.push({i, cols - 1});
            }
        }

        for (int j = 0; j < cols; j++)
        {
            if (board[0][j] == 'O')
            {
                tasks.push({0, j});
            }
            if (board[rows - 1][j] == 'O')
            {
                tasks.push({rows - 1, j});
            }
        }

              while (!tasks.empty())
        {
            auto curr = tasks.front();
            tasks.pop();
            int i = curr.first;
            int j = curr.second;

            if (board[i][j] != 'O')
                continue;

            board[i][j] = 'T';

            if (i + 1 < rows && board[i + 1][j] == 'O')
            {
                tasks.push({i + 1, j});
            }
            if (i - 1 >= 0 && board[i - 1][j] == 'O')
            {
                tasks.push({i - 1, j});
            }
            if (j + 1 < cols && board[i][j + 1] == 'O')
            {
                tasks.push({i, j + 1});
            }
            if (j - 1 >= 0 && board[i][j - 1] == 'O')
            {
                tasks.push({i, j - 1});
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
int main()
{

    return 0;
}