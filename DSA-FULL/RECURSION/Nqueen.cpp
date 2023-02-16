#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
void print(vector<vector<string>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "solution " << i + 1;
        cout << endl;
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
}
class solution
{
public:
    void solve(vector<vector<string>> &ans, vector<string> &board, int col, vector<int> &lowdia, vector<int> &updia, vector<int> leftrow, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 && lowdia[row + col] == 0 && updia[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowdia[row + col] = 1;
                updia[n - 1 + col - row] = 1;
                solve(ans, board, col + 1, lowdia, updia, leftrow, n);
                board[row][col] = '_';
                leftrow[row] = 0;
                lowdia[row + col] = 0;
                updia[n - 1 + col - row] = 0;
            }
        }
    };

    vector<vector<string>> helper(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '_');
        vector<int> lowdia(2 * n - 1, 0);
        vector<int> updia(2 * n - 1, 0);
        vector<int> leftrow(n, 0);
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(ans, board, 0, lowdia, updia, leftrow, n);
        return ans;
    };
};
int main()
{
    solution obj1;
    int n;
    n = 8;
    vector<vector<string>> ans = obj1.helper(n);
    print(ans);

    return 0;
}