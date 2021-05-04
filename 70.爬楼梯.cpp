/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * DP动态规划
 * dp[n] = dp[n-1] + dp[n-2]
 * 
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int pre2 = 1, pre1 = 2, cur;
        for (int i = 3; i <= n; ++i)
        {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};
// @lc code=end

