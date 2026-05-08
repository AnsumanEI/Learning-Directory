#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &unlock, vector<int> &state)
    {
        if (state[node] == 1)
        {
            return true;
        }
        if (state[node] == 2)
        {
            return false;
        }
        bool val;
        state[node] = 1;
        for (auto &p : unlock[node])
        {
            if (dfs(p, unlock, state))
            {
                return true;
            }
        }
        state[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> unlock(numCourses);
        vector<int> state(numCourses, 0);
        for (auto &p : prerequisites)
        {
            int a = p[0];
            int b = p[1];
            unlock[b].push_back(a);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (dfs(i, unlock, state))
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{

    return 0;
}