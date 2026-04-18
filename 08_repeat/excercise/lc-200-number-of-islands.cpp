#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void dfs(vector<vector<char>> &grid, int x, int y)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (x < 0 || x >= rows || y < 0 || y >= cols)
        return;
    if (grid[x][y] == '0')
        return;

    grid[x][y] = '0';
    dfs(grid, x + 1, y);
    dfs(grid, x - 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1);
}
int main()
{
    int numIsl;
    vector<vector<char>> grid;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                numIsl++;
            }
        }
    }
    cout << numIsl;
    return 0;
}