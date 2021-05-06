/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(robRange(nums, 0, n - 1), robRange(nums, 1, n));
    }
    int robRange(vector<int> &nums, int l, int h)
    {
        if (h - l <= 0)
            return 0;
        int prev = 0,cur = nums[l],tmp;
        for (int i = l + 1; i < h; ++i)
        {
            tmp = cur;
            cur = max(cur,prev+nums[i]);
            prev = tmp;
        }
        return cur;
    }
};
// @lc code=end

