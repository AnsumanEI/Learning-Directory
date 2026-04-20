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
    int edit(string &w1, string &w2, int i, int j, vector<vector<int>> &memo)
    {
        if (w1.size() == 0)
            return w2.size();
        if (w2.size() == 0)
            return w1.size();
        if (i < 0)
            return j + 1;
        else if (j < 0)
            return i + 1;
        if (memo[i][j] != -1)
            return memo[i][j];

        if (w1[i] == w2[j])
        {
            memo[i][j] = edit(w1, w2, i - 1, j - 1, memo);
        }
        else
        {
            memo[i][j] = 1 + min({edit(w1, w2, i - 1, j - 1, memo),
                                  edit(w1, w2, i, j - 1, memo),
                                  edit(w1, w2, i - 1, j, memo)});
        }

        return memo[i][j];
    }
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return edit(word1, word2, m - 1, n - 1, memo);
    }
};
int main()
{

    return 0;
}