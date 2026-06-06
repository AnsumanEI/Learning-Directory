#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;
    int NodeVal;

    TrieNode()
    {
        isEnd = false;
        NodeVal = 0;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class MapSum
{
    unordered_map<string, int> mapping;
    TrieNode *root;

public:
    MapSum()
    {
        root = new TrieNode();
    }
    void trieinsert(string &key, int val)
    {
        TrieNode *curr = root;
        for (int i = 0; i < key.size(); i++)
        {
            int ch = key[i];
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
            {
                curr->children[index] = new TrieNode();
            }
            curr->NodeVal += val;
            curr = curr->children[index];
        }
        curr->NodeVal += val;
        curr->isEnd = true;
    }
    void insert(string key, int val)
    {
        int delta = val;
        if (mapping.count(key))
        {
            delta = val - mapping[key];
        }
        mapping[key] = val;
        trieinsert(key, delta);
    }

    int sum(string prefix)
    {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int ch = prefix[i];
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
            {
                return 0;
            }
            curr = curr->children[index];
        }
        return curr->NodeVal;
    }
};

int main()
{

    return 0;
}