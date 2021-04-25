/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * k-th -- 桶排序
 * 
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> counts;
        int max_count = 0;
        for (int num : nums)
            max_count = max(max_count, ++counts[num]);

        vector<vector<int>> buckets(max_count + 1);
        for (auto p : counts)
            buckets[p.second].push_back(p.first);

        vector<int> ans;
        for (int i = max_count; i >= 0 && ans.size() < k; --i)
            for (int num : buckets[i])
                ans.push_back(num);
        return ans;
    }
};
// @lc code=end

