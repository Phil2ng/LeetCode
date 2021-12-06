/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * 遍历
 * 
 * [1816] 截断句子
 */

// @lc code=start
class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string ans;
        for (auto &&c : s)
        {
            if (c == ' ')
            {
                k--;
            }
            if (k == 0)
            {
                break;
            }
            ans += c;
        }
        return ans;
    }
};
// @lc code=end

