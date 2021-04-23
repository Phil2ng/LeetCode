/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * 二分查找，双指针
 * 时间复杂度O(logN)
 * 
 * [81] 搜索旋转排序数组 II
 */

// @lc code=end
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2, start = nums[l], end = nums[r], midNum = nums[mid];
            if (midNum == target)
                return true;
            if (midNum == end) //处理特例 如：101111,111101。
                --r;
            else if (midNum < end)
            {
                if (target > midNum && target <= end)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                if (target >= start && target < midNum)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end