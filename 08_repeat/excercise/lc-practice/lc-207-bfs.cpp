#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> tasks;
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
                tasks.push(i);
            }
        }
        int count = 0;
        while (!tasks.empty())
        {
            int temp = tasks.front();
            count++;
            tasks.pop();

            for (auto &p : adj[temp])
            {
                indegree[p]--;
                if (indegree[p] == 0)
                {
                    tasks.push(p);
                }
            }
        }
        return count == numCourses;
    }
};
int main()
{

    return 0;
}