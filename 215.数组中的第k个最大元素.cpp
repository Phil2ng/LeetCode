/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * k-th Element -- 基于快速排序的选择方法
 * 
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelectKthElement(nums, 0, nums.size() - 1, nums.size() - k);
    }
    int quickSelectKthElement(vector<int> &nums, int l, int r, int k)
    {
        int q = partition(nums, l, r);
        if (q == k)
            return nums[q];
        else
            return q < k ? quickSelectKthElement(nums, q + 1, r, k) : quickSelectKthElement(nums, l, q - 1, k);
    }
    int partition(vector<int> &nums, int l, int r)
    {
        srand(time(0));
        swap(nums[r], nums[rand() % (r - l + 1) + l]);
        for (int i = l; i < r; ++i)
            if (nums[i] < nums[r])
                swap(nums[i], nums[l++]);
        swap(nums[l], nums[r]);
        return l;
    }
};
// @lc code=end
