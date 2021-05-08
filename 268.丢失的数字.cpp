/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            // ans ^= i ^ nums[i];
            ans += i - nums[i];
        }
        return ans;
    }
};
// @lc code=end
