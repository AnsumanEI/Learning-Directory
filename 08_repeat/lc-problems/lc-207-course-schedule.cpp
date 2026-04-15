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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> unlocked;

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
                unlocked.push(i);
        }
        int count = 0;
        while (!unlocked.empty())
        {
            int achievablecourses = unlocked.front();
            unlocked.pop();
            count++;

            for (auto &p : adj[achievablecourses])
            {
                indegree[p]--;
                if (indegree[p] == 0)
                {
                    unlocked.push(p);
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