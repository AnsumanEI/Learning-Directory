#include <iostream>
#include <vector>
using namespace std;

// ----------------------------------------------------------------
//  LeetCode #200 — Number of Islands
// ----------------------------------------------------------------
//
//  PROBLEM:
//  Given a 2D grid of '1's (land) and '0's (water), count the
//  number of islands. An island is surrounded by water and is
//  formed by connecting adjacent land cells horizontally or
//  vertically.
//
//  INTUITION:
//  Every time we find an unvisited '1', we've found a new island.
//  We then flood-fill all connected land cells (marking them '0'
//  so we don't count them again) before moving on.
//
//  APPROACH: DFS Flood Fill
//
//    - Iterate over every cell in the grid.
//    - When a '1' is found, increment the island count and run
//      DFS to sink the entire island (mark all connected '1's
//      as '0').
//    - DFS recurses in all 4 directions, stopping at boundaries
//      or water cells.
//
//  COMPLEXITY:
//    Time  : O(m * n) — each cell is visited at most once
//    Space : O(m * n) — call stack in worst case (all land)
//
//  MISTAKES TO AVOID:
//  ❌ Forgetting to mark visited cells → infinite loop
//  ✅ Mark grid[x][y] = '0' before recursing, not after
// ----------------------------------------------------------------

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int xlen = grid.size();
        int ylen = grid[0].size();
        if (x < 0 || x >= xlen || y < 0 || y >= ylen) return;
        if (grid[x][y] == '0') return;

        grid[x][y] = '0';
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int numIsl = 0;
        int xlen = grid.size();
        int ylen = grid[0].size();
        for (int x = 0; x < xlen; x++) {
            for (int y = 0; y < ylen; y++) {
                if (grid[x][y] == '1') {
                    dfs(grid, x, y);
                    numIsl++;
                }
            }
        }
        return numIsl;
    }
};

// ----------------------------------------------------------------
//  MAIN — Test LC #200
// ----------------------------------------------------------------

int main() {
    Solution sol;

    // Input:  grid with 3 islands
    // Output: 3
    vector<vector<char>> grid1 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of Islands (expect 3): " << sol.numIslands(grid1) << "\n";

    // Input:  grid with 1 large island
    // Output: 1
    vector<vector<char>> grid2 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << "Number of Islands (expect 1): " << sol.numIslands(grid2) << "\n";

    return 0;
}
