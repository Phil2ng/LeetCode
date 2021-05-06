/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, ans = nums[0];
        for (int num : nums)
        {
            sum = max(num, sum + num);
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end
