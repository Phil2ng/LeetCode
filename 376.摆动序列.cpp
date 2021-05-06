/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * 状态机维护up、down
 * 另外，利用性质贪心法更高效
 * 
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> up(n + 1, 1), down(n + 1, 1);
        for (int i = 1; i < n; ++i)
        {
            up[i + 1] = up[i];
            down[i + 1] = down[i];
            if (nums[i] > nums[i - 1])
            {
                up[i + 1] = max(up[i], down[i] + 1);
            }
            else if (nums[i] < nums[i - 1])
            {
                down[i + 1] = max(down[i], up[i] + 1);
            }
        }
        return max(up[n], down[n]);
    }
};
// @lc code=end

