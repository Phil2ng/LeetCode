/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * 相向三指针遍历
 * 
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int> &nums)
    {
        // all in [0, l)   < 1
        // all in [l, i)   = 1
        // all in [r, len) > 1
        int l = 0, r = nums.size(), i = 0;
        while (i < r)
        {
            if (nums[i] < 1)
                swap(nums[i++], nums[l++]);
            else if (nums[i] > 1)
                swap(nums[i], nums[--r]);
            else
                i++;
        }
    }
};
// @lc code=end

