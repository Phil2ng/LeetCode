/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans;
        while (columnNumber)
        {
            --columnNumber;
            ans = char('A' + (columnNumber % 26)) + ans;
            columnNumber /= 26;
        }
        // while (columnNumber)
        // {
        //     int c = (columnNumber % 26 - 1 + 26) % 26;
        //     ans = (char)(c + 'A') + ans;
        //     columnNumber = (columnNumber - c) / 26;
        // }
        return ans;
    }
};
// @lc code=end
