/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * 二分查找，双指针
 * 时间复杂度O(logN)
 * 
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, ret = nums[0];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            while (l < mid && nums[mid] == nums[l])
                l++;
            if (nums[mid] >= nums[l])
            {
                ret = min(ret, nums[l]);
                l = mid + 1;
            }
            else
            {
                ret = min(ret, nums[mid]);
                r = mid - 1;
            }
        }
        return ret;
    }
};
// @lc code=end
