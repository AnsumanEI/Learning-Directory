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
    bool dfs(int node, vector<int> &state, vector<vector<int>> &adj, vector<int> &result)

    {
        state[node] = 1;

        for (auto &p : adj[node])
        {
            if (state[p] == 1)
            {
                return false;
            }
            else if (state[p] == 2)
            {
                continue;
            }
            else if (state[p] == 0)
            {
                if (!dfs(p, state, adj, result))
                {
                    return false;
                }
            }
        }

        result.push_back(node);
        state[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> state(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> results;

        for (auto &p : prerequisites)
        {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (state[i] == 0)
            {
                if (!dfs(i, state, adj, results))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{

    return 0;
}