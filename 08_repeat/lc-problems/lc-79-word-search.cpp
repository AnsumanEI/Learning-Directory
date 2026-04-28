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
    bool dfs(vector<vector<char>> &board, string word, vector<vector<bool>> &visited, int i, int j, int ind)
    {

        int m = board.size();    // ver len
        int n = board[0].size(); // horzlen
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return false;
        }
        if (visited[i][j] == true)
        {
            return false;
        }

        if (board[i][j] == word[ind])
        {
            if (ind == word.size() - 1) // one element check as ind has not incremented yet , smarter check instead of doin ind+1 after recursion
                return true;
            visited[i][j] = true;
            if (dfs(board, word, visited, i + 1, j, ind + 1))
                return true;
            if (dfs(board, word, visited, i - 1, j, ind + 1))
                return true;
            if (dfs(board, word, visited, i, j + 1, ind + 1))
                return true;
            if (dfs(board, word, visited, i, j - 1, ind + 1))
                return true;
            visited[i][j] = false;
        }
        else
        {

            return false;
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();    // ver len
        int n = board[0].size(); // horzlen

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(board, word, visited, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{

    return 0;
}