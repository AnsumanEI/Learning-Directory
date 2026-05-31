#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void bfs(vector<vector<int>> heights, vector<vector<bool>> &visited, queue<pair<int, int>> &checked)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        while (!checked.empty())
        {
            auto [cx, cy] = checked.front();

            checked.pop();

            if (cx + 1 < rows && !visited[cx + 1][cy] && heights[cx + 1][cy] >= heights[cx][cy])
            {
                checked.push({cx + 1, cy});
                visited[cx + 1][cy] = true;
            }
            if (cx - 1 >= 0 && !visited[cx - 1][cy] && heights[cx - 1][cy] >= heights[cx][cy])
            {
                checked.push({cx - 1, cy});
                visited[cx - 1][cy] = true;
            }
            if (cy + 1 < cols && !visited[cx][cy + 1] && heights[cx][cy + 1] >= heights[cx][cy])
            {
                checked.push({cx, cy + 1});
                visited[cx][cy + 1] = true;
            }
            if (cy - 1 >= 0 && !visited[cx][cy - 1] && heights[cx][cy - 1] >= heights[cx][cy])
            {
                checked.push({cx, cy - 1});
                visited[cx][cy - 1] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        queue<pair<int, int>> pac, atl;

        for (int i = 0; i < rows; i++)
        {
            pac.push({i, 0});
            pacific[i][0] = true;
            atl.push({i, cols - 1});
            atlantic[i][cols - 1] = true;
        }

        for (int i = 0; i < cols; i++)
        {
            pac.push({0, i});
            pacific[0][i] = true;
            atl.push({rows - 1, i});
            atlantic[rows - 1][i] = true;
        }
        bfs(heights, pacific, pac);
        bfs(heights, atlantic, atl);
        vector<vector<int>> results;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    results.push_back({i, j});
                }
            }
        }
        return results;
    }
};
int main()
{

    return 0;
}