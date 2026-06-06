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
class WordDictionary {
public:
TrieNode * root ;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * curr  = root ;
        for ( int i = 0 ; i < word.size(); i++)
        {
            int ch = word[i];
            int index = ch - 'a';
            if(curr->children[index] == nullptr)
            {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
    bool helper(string &word , int index , TrieNode * curr)
    {
        if(index == word.size())
        {
            return curr->isEnd;
        }
        if (word[index] == '.')
        {
            for ( int i  = 0 ; i < 26 ; i++)
            {
                if (curr->children[i]!= nullptr)
                {
                    if(helper(word , index +1 , curr->children[i]))
                    {
                        return true;
                    }
                }
            }
            return false ;
        }
        int ch = word[index];
        int ind = ch - 'a';
        if ( curr->children[ind] == nullptr)
        {
            return false;
        }

        return helper(word , index +1 , curr->children[ind]);
    }
    bool search(string word) {
        return helper(word , 0 , root);
    }
};

int main() {
    
    return 0;
}