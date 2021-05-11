/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class TrieNode
{
public:
    bool isVal;
    TrieNode *childNode[26];
    TrieNode() : isVal(false)
    {
        for (int i = 0; i < 26; ++i)
        {
            childNode[i] = nullptr;
        }
    }
};
class Trie
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (cur->childNode[word[i] - 'a'] == nullptr)
            {
                cur->childNode[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->childNode[word[i] - 'a'];
        }
        cur->isVal = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (!cur)
                break;
            cur = cur->childNode[word[i] - 'a'];
        }
        return cur ? cur->isVal : false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.length(); ++i)
        {
            if (!cur)
                break;
            cur = cur->childNode[prefix[i] - 'a'];
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
