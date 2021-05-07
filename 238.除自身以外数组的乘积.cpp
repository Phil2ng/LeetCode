/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> L(n, 1), R(n, 1), ans(n);
        for (int i = 1; i < n; ++i)
        {
            L[i] = nums[i - 1] * L[i - 1];
            R[n - 1 - i] = nums[n - i] * R[n - i];
        }
        for (int i = 0; i < n; ++i)
        {
            ans[i] = L[i] * R[i];
        }
        return ans;
    }
};
// @lc code=end

