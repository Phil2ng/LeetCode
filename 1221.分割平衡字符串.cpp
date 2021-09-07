/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * 贪心,遍历
 * 
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int cnt = 0, ans = 0;
        for (auto &&c : s)
        {
            if (c == 'L')
                cnt++;
            else
                cnt--;
            if (cnt == 0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

