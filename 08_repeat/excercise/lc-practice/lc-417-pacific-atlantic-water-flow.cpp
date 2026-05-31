#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void bfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, queue<pair<int, int>> &tasks)
    {
        int rows = heights.size();
        int cols = heights[0].size();
        while (!tasks.empty())
        {
            auto [cx, cy] = tasks.front();
            tasks.pop();

            if (cx + 1 < rows && !visited[cx + 1][cy] && heights[cx + 1][cy] >= heights[cx][cy])
            {
                tasks.push({cx + 1, cy});
                visited[cx + 1][cy] = true;
            }
            if (cx - 1 >= 0 && !visited[cx - 1][cy] && heights[cx - 1][cy] >= heights[cx][cy])
            {
                tasks.push({cx - 1, cy});
                visited[cx - 1][cy] = true;
            }
            if (cy + 1 < cols && !visited[cx][cy + 1] && heights[cx][cy + 1] >= heights[cx][cy])
            {
                tasks.push({cx, cy + 1});
                visited[cx][cy + 1] = true;
            }
            if (cy - 1 >= 0 && !visited[cx][cy - 1] && heights[cx][cy - 1] >= heights[cx][cy])
            {
                tasks.push({cx, cy - 1});
                visited[cx][cy - 1] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pac_vis(rows, vector<bool>(cols, false));
        queue<pair<int, int>> pac_q;

        vector<vector<bool>> atl_vis(rows, vector<bool>(cols, false));
        queue<pair<int, int>> atl_q;

        for (int i = 0; i < cols; i++)
        {
            pac_vis[0][i] = true;
            pac_q.push({0, i});
            atl_vis[rows - 1][i] = true;
            atl_q.push({rows - 1, i});
        }
        for (int i = 0; i < rows; i++)
        {
            pac_vis[i][0] = true;
            pac_q.push({i, 0});
            atl_vis[i][cols - 1] = true;
            atl_q.push({i, cols - 1});
        }

        bfs(heights, pac_vis, pac_q);
        bfs(heights, atl_vis, atl_q);

        vector<vector<int>> res;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pac_vis[i][j] && atl_vis[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
int main()
{

    return 0;
}