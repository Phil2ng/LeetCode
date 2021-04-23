/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * 
 * 二分查找，双指针
 * lower_bound、upper_bound的实现
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int p1 = lower_bound(nums, target);
        int p2 = upper_bound(nums, target) - 1;
        if (p1 == nums.size() || nums[p1] != target)
            return vector<int>{-1, -1};
        return vector<int>{p1, p2};
    }
    int lower_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    int upper_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size(), mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
// @lc code=end