/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * 滑动窗口
 * 
 * [1838] 最高频元素的频数
 */

// @lc code=start
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0, ans = 1, n = nums.size();
        long total = 0;
        for (int r = 1; r < n; ++r)
        {
            total += long(r - l) * (nums[r] - nums[r - 1]);
            while (total > k)
            {
                total -= nums[r] - nums[l];
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @lc code=end

