/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] 常数时间插入、删除和获取随机元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class RandomizedSet {
    vector<int> list;
    unordered_map<int,int> dict;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.count(val)) return false;
        dict[val] = list.size();
        list.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dict.count(val)==0) return false;
        list[dict[val]]= list[list.size()-1];
        dict[list[list.size()-1]] = dict[val];
        list.pop_back();
        dict.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return list[rand()%(list.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

