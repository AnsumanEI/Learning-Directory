#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
        for (auto &p : children)
        {
            p = nullptr;
        }
        isEnd = false;
    }
};
class Solution
{
    TrieNode *root;

public:
    Solution()
    {
        root = new TrieNode();
    }
    void insert(string &word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            int ch = word[i];
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
            {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
    void dfshelper(vector<vector<char>> &board, vector<string> &res, string path, TrieNode *curr, int i, int j)
    {
        int rows = board.size();
        int cols = board[0].size();

        if (i >= rows || i < 0 || j >= cols || j < 0)
        {
            return;
        }
        if (board[i][j] == '#')
        {
            return;
        }
        int ch = board[i][j];
        char temp = board[i][j];
        int index = ch - 'a';
        if (curr->children[index] == nullptr)
        {
            return;
        }
        path.push_back(ch);
        board[i][j] = '#';
        curr = curr->children[index];

        if (curr->isEnd == true)
        {
            res.push_back(path);
            curr->isEnd = false;
        }

        dfshelper(board, res, path, curr, i + 1, j);
        dfshelper(board, res, path, curr, i - 1, j);
        dfshelper(board, res, path, curr, i, j + 1);
        dfshelper(board, res, path, curr, i, j - 1);
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<string> res;
        for (auto &word : words)
        {
            insert(word);
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                TrieNode *curr = root;
                string path;
                int ch = board[i][j];
                int index = ch - 'a';
                if (curr->children[index] != nullptr)
                {
                    dfshelper(board, res, path, curr, i, j);
                }
            }
        }
        return res;
    }
};
int main()
{

    return 0;
}