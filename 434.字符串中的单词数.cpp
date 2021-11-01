/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution
{
public:
    int countSegments(string s)
    {
        int n = s.size(), ans = 0, t = 1;
        for (auto &&c : s)
        {
            if (t)
            {
                t = 0;
                if (c != ' ')
                {
                    ans++;
                }
            }
            if (c == ' ')
            {
                t = 1;
            }
        }
        return ans;
    }
};
// @lc code=end
