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
    bool isValid(string s)
    {
        unordered_map<char, char> mappings;
        mappings['}'] = '{';
        mappings[']'] = '[';
        mappings[')'] = '(';

        stack<char> latest;

        for (auto &p : s)
        {
            if (p == NULL)
                return true;

            if (mappings.count(p))
            {
                if (latest.empty())
                    return false;
                if (latest.top() != mappings[p])
                    return false;
                latest.pop();
            }
            else
                latest.push(p);
        }

        return latest.empty();
    }
};
int main()
{

    return 0;
}