#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class MinStack
{
public:
    stack<pair<int, int>> virt;
    MinStack()
    {
    }

    void push(int val)
    {
        if (virt.empty())
        {
            virt.push({val, val});
        }
        else if (val <= virt.top().second)
        {
            virt.push({val, val});
        }
        else
        {
            int min = virt.top().second;
            virt.push({val, min});
        }
    }

    void pop()
    {
        if (!virt.empty())
        {
            virt.pop();
        }
        else
            return;
    }

    int top()
    {
        if (virt.empty())
            return NULL;
        return virt.top().first;
    }

    int getMin()
    {
        if (virt.empty())
        {
            return NULL;
        }
        else
        {
            return virt.top().second;
        }
    }
};
int main()
{

    return 0;
}