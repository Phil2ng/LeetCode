/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = i - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] > nums[i])
                {
                    ans += r - l;
                    r--;
                }
                else
                    l++;
            }
        }
        return ans;
    }
};
// @lc code=end

