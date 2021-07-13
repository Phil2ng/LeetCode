/*
 * @lc app=leetcode.cn id=1818 lang=cpp
 *
 * 二分查找
 * 
 * [1818] 绝对差值和
 */

// @lc code=start
class Solution
{
    static constexpr int MOD = 1e9 + 7;

public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> arr(nums1);
        sort(arr.begin(), arr.end());
        long sum = 0, ans = LONG_MAX;
        int n = nums1.size();
        for (int i = 0; i < n; ++i)
        {
            sum += abs(nums1[i] - nums2[i]);
        }
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(arr.begin(), arr.end(), nums2[i]);
            if (it != arr.begin())
                ans = min(ans, sum - abs(nums1[i] - nums2[i]) + abs(nums2[i] - *(it - 1)));
            if (it != arr.end())
                ans = min(ans, sum - abs(nums1[i] - nums2[i]) + abs(nums2[i] - *(it)));
        }
        return ans % MOD;
    }
};

// @lc code=end

