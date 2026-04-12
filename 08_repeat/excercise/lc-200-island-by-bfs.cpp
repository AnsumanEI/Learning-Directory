#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;

void bfs(vector<vector<char>> &grid, int x, int y)
{
    queue<pair<int, int>> q;
    int rows = grid.size();
    int cols = grid[0].size();
    {
        q.push({x, y});
        grid[x][y] = '0';
        while (!q.empty())
        {
            /*pair <int , int > current = q.front();
            int temp1= current.first;
            int temp2= current.second; or we can */
            auto [cx, cy] = q.front();
            q.pop();
            if (cx + 1 < rows && grid[cx + 1][cy] == '1')
            {
                q.push({cx + 1, cy});
                grid[cx + 1][cy] = '0';
            }
            if (cx - 1 >= 0 && grid[cx - 1][cy] == '1')
            {
                q.push({cx - 1, cy});
                grid[cx - 1][cy] = '0';
            }
            if (cy + 1 < cols && grid[cx][cy + 1] == '1')
            {
                q.push({cx, cy + 1});
                grid[cx][cy + 1] = '0';
            }
            if (cy - 1 >= 0 && grid[cx][cy - 1] == '1')
            {
                q.push({cx, cy - 1});
                grid[cx][cy - 1] = '0';
            }
        }
    }
}
int main()
{
    vector<vector<char>> grid;
    int numIsl = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int x = 0; x < rows; x++)
    {

        for (int y = 0; y < cols; y++)
        {
            if (grid[x][y] == '1')
            {
                bfs(grid, x, y);
                numIsl++;
            }
        }
    }
    return numIsl;
}