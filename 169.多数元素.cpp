/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ans, cnt = 0;
        for (int &num : nums)
        {
            if (cnt == 0)
            {
                ans = num;
                ++cnt;
            }
            else
            {
                if (num == ans)
                    ++cnt;
                else
                    --cnt;
            }
        }
        return ans;
    }
};
// @lc code=end
