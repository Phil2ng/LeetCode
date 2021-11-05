/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * 动态规划+哈希表
 * 
 * [1218] 最长定差子序列
 */

// @lc code=start
class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> cnt;
        for (auto &&a : arr)
        {
            cnt[a] = cnt[a - difference] + 1;
        }
        int ans = 0;
        for (auto &&c : cnt)
        {
            ans = max(ans, c.second);
        }
        return ans;
    }
};
// @lc code=end
