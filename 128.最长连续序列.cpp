/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> hash;
        for (int &num : nums)
            hash.insert(num);
        int ans = 0;
        while (!hash.empty())
        {
            int cur = *(hash.begin());
            int next = cur + 1, prev = cur - 1;
            hash.erase(cur);
            while (hash.count(next))
                hash.erase(next++);
            while (hash.count(prev))
                hash.erase(prev--);
            ans = max(ans, next - prev - 1);
        }
        return ans;
    }
};
// @lc code=end

