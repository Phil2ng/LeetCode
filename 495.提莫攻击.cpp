/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * 遍历
 * 
 * [495] 提莫攻击
 */

// @lc code=start
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int n = timeSeries.size(), ans = duration;
        for (int i = 1; i < n; i++)
        {
            ans += min(timeSeries[i] - timeSeries[i - 1], duration);
        }
        return ans;
    }
};
// @lc code=end

