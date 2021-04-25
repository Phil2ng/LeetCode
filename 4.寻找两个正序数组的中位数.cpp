/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * k-th --二分查找，双指针
 * 时间复杂度为 O(log (m+n)) 
 * 
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int mn = nums1.size() + nums2.size();
        if (mn % 2)
            return getKthElement(nums1, nums2, mn / 2 + 1);
        else
            return (getKthElement(nums1, nums2, mn / 2) + getKthElement(nums1, nums2, mn / 2 + 1)) / 2.0;
    }

    int getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        int low1 = 0, low2 = 0, m = nums1.size(), n = nums2.size();
        while (true)
        {
            if (low1 == m)
                return nums2[low2 + k - 1];
            if (low2 == n)
                return nums1[low1 + k - 1];
            if (k == 1)
                return min(nums1[low1], nums2[low2]);
            int idx1 = min(low1 + k / 2 - 1, m - 1);
            int idx2 = min(low2 + k / 2 - 1, n - 1);
            if (nums1[idx1] <= nums2[idx2])
            {
                k -= idx1 - low1 + 1;
                low1 = idx1 + 1;
            }
            else
            {
                k -= idx2 - low2 + 1;
                low2 = idx2 + 1;
            }
        }
    }

    // 数学解法  时间复杂度为 O(log min(m,n)) 
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;

        while (left <= right)
        {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums_i = (i == m ? INT_MAX : nums1[i]);
            int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums_j = (j == n ? INT_MAX : nums2[j]);

            if (nums_im1 <= nums_j)
            {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            }
            else
            {
                right = i - 1;
            }
        }

        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};
// @lc code=end

