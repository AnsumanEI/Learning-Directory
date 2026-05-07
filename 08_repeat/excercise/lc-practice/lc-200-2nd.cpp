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
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        int r = grid.size();
        int c = grid[0].size();

        if (x >= r || x < 0 || y >= c || y < 0)
        {
            return;
        }
        if (grid[x][y] == '0')
        {
            return;
        }
        grid[x][y] = '0';

        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int island = 0;
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }
};
int main()
{

    return 0;
}