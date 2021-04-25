/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * 桶排序
 * 
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> counts;
        int max_count = 0;
        for (char c : s)
            max_count = max(max_count, ++counts[c]);

        vector<vector<char>> buckets(max_count + 1);
        for (auto p : counts)
            buckets[p.second].push_back(p.first);

        string ans = "";
        for (int i = max_count; i >= 0; --i)
            for (char c : buckets[i])
                for (int j = 0; j < i; j++)
                    ans += c;
        return ans;
    }
};
// @lc code=end
