/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * 动态规划 定义dp[n]为 以nums[n]结尾的等差数列个数
 * dp[n] = dp[n-1] + 1
 *       = 0
 * 
 * [413] 等差数列划分
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        vector<int> dp(n, 0);
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end
