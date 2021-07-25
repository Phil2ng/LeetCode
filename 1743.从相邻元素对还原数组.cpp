/*
 * @lc app=leetcode.cn id=1743 lang=cpp
 *
 * [1743] 从相邻元素对还原数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_multimap<int, int> hash;
        unordered_map<int, int> cnt;
        for (auto &&a : adjacentPairs)
        {
            cnt[a[0]]++;
            cnt[a[1]]++;
            hash.emplace(a[0], a[1]);
            hash.emplace(a[1], a[0]);
        }
        int t;
        for (auto &&i : cnt)
        {
            if (i.second == 1)
            {
                t = i.first;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(t);
        cnt[t] = 0;
        auto x = hash.equal_range(t);
        while (x.first != x.second)
        {
            if (cnt[x.first->second] == 0)
                x.first++;
            if (x.first == x.second || cnt[x.first->second] == 0)
                break;
            cnt[x.first->second] = 0;
            ans.push_back(x.first->second);
            x = hash.equal_range(ans.back());
        }
        return ans;
    }
};
// @lc code=end

