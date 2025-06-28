#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class solution
{
public:
    vector<int> twosum(vector<int> nums, int target)
    {
        map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int more = target - nums[i];
            cout << "more " << more;
            if (m.find(more) != m.end())
            {
                return {m[more], i};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};
int main()
{
    vector<int> num{2, 6, 5, 8, 11};
    vector<int> sol(2);
    solution obj;
    sol = obj.twosum(num, 19);
    for (int val : sol)
    {
        cout << val << endl;
    }
    return 0;
}