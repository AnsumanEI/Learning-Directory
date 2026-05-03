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
    bool isValid(string s)
    {
        unordered_map<char, char> mappings;
        mappings['}'] = '{';
        mappings[']'] = '[';
        mappings[')'] = '(';
        stack<char> latest;

        for (auto &p : s)
        {
            if (mappings.count(p))
            {
                if (latest.empty())
                    return false;
                if (mappings[p] != latest.top())
                    return false;
                latest.pop();
            }
            else
            {
                latest.push(p);
            }
        }
        return latest.empty();
    }
};
int main()
{

    return 0;
}