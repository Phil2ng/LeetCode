/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * dp[n] = k, 以n结尾的最长递增子序列长度k
 * dp[n] = 1+ max{ dp[0],dp[2],...,dp[n-1]} 当nums[n]>nums[j]
 * 
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), ans = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    // int lengthOfLIS(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     if (n <= 1)
    //         return n;
    //     vector<int> dp;
    //     dp.push_back(nums[0]);
    //     for (int i = 1; i < n; ++i)
    //     {
    //         if (dp.back() < nums[i])
    //         {
    //             dp.push_back(nums[i]);
    //         }
    //         else
    //         {
    //             auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
    //             *itr = nums[i];
    //         }
    //     }
    //     return dp.size();
    // }
};
// @lc code=end

