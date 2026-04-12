#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;

void bfs(vector<vector<char>>& grid , int x , int y)
{
    queue<pair<int , int>> q ;
while(!q.empty())
    {q.push({x,y});
    if(grid[x+1][y]) q.push({x+1 , y});
    if(grid[x-1][y])q.push({x-1 , y});;
    if(grid[x][y+1])q.push({ x, y+1});;
    if(grid[x][y-1])q.push({x,y-1});;}

}

int main()
{
    vector<vector<char>>grid ;
    int numIsl = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int x = 0 ; x< rows ; x++) {

        for ( int y = 0 ; y < cols ;y++ )
        {
            if (grid[x][y]== '1'){
                bfs(grid , x , y);
                numIsl++;
            }
        }

    }
    return numIsl;
}