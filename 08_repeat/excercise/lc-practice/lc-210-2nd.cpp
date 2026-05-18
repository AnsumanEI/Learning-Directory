#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> courses;
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
                courses.push(i);
            }
        }

        while (!courses.empty())
        {
            int toprocess = courses.front();
            res.push_back(toprocess);
            courses.pop();
            for (auto &p : adj[toprocess])
            {
                indegree[p]--;
                if (indegree[p] == 0)
                {
                    courses.push(p);
                }
            }
        }

        return numCourses == res.size() ? res : vector<int>{};
    }
};
int main()
{
    return 0;
}