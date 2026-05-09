#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> unlocked;
        vector<int> res;
        for (auto &p : prerequisites)
        {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                unlocked.push(i);
            }
        }
        while (!unlocked.empty())
        {
            int temp = unlocked.front();
            res.push_back(temp);
            unlocked.pop();
            for (auto &p : adj[temp])
            {
                indegree[p]--;
                if (indegree[p] == 0)
                {
                    unlocked.push(p);
                }
            }
        }
        if (res.size() == numCourses)
        {
            return res;
        }
        return {};
    }
};
int main()
{
    return 0;
}