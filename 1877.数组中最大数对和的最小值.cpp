/*
 * @lc app=leetcode.cn id=1877 lang=cpp
 *
 * 排序+贪心
 * [1877] 数组中最大数对和的最小值
 */

// @lc code=start
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (size_t i = 0; i < n / 2; i++)
        {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }
        return ans;
    }
};
// @lc code=end

