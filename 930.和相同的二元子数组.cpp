/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * 滑动窗口
 * 
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int right = 0, left1 = 0, left2 = 0, ans = 0, n = nums.size(), sum1 = 0, sum2 = 0;
        while (right < n)
        {
            sum1 += nums[right];
            while (left1 <= right && sum1 > goal)
            {
                sum1 -= nums[left1];
                left1++;
            }
            sum2 += nums[right];
            while (left2 <= right && sum2 >= goal)
            {
                sum2 -= nums[left2];
                left2++;
            }
            ans += left2 - left1;
            right++;
        }
        return ans;
    }
};
// @lc code=end

