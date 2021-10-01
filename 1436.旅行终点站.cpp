/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * 哈希表,计数
 * 
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> cnt;
        for (auto &&p : paths)
        {
            cnt[p[0]] += 1;
            cnt[p[1]] += 2;
        }
        for (auto &&s : cnt)
        {
            if (s.second == 2)
            {
                return s.first;
            }
        }
        return "";
    }
};
// @lc code=end

