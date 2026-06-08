#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sink(vector<vector<char>> &grid, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= cols)
        {
            return;
        }
        if (grid[i][j] == '0')
        {
            return;
        }
        grid[i][j] = '0';
        sink(grid, i + 1, j);
        sink(grid, i - 1, j);
        sink(grid, i, j + 1);
        sink(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int num = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    sink(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }
};
int main()
{

    return 0;
}