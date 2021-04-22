/*
 * 指针遍历
 * 时间复杂度：O(m+n) 空间复杂度：O(1)
 * 
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        while (n > 0)
        {
            nums1[m + n] = m < 1 || nums2[n - 1] > nums1[m - 1] ? nums2[--n] : nums1[--m];
        }
    }
};
// @lc code=end
