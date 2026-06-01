#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
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

    bool search(string word)
    {
        auto curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            int ch = word[i];
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
            {
                return false;
            }
            curr = curr->children[index];
        }

        return curr->isEnd;
    }

    bool startsWith(string word)
    {
        auto curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            int ch = word[i];
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
            {
                return false;
            }
            curr = curr->children[index];
        }

        return true;
    }
};
int main()
{

    return 0;
}