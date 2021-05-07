/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * x-a + b-x = b - a ,即最终全都变成中位数
 * 
 * [462] 最少移动次数使数组元素相等 II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j)
        {
            ans += nums[j] - nums[i];
        }
        return ans;
    }
};
// @lc code=end

