/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class LRUCache
{
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int size;

public:
    LRUCache(int capacity) : size(capacity)
    {
    }

    int get(int key)
    {
        auto it = hash.find(key);
        if (it == hash.end())
            return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it = hash.find(key);
        if (it != hash.end())
        {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
        }
        else
        {
            cache.insert(cache.begin(), make_pair(key, value));
            hash[key] = cache.begin();
            if (cache.size() > size)
            {
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
