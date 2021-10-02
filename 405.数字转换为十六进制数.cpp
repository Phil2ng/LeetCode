/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * 位运算
 * 
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        string ans;
        for (int i = 7; i >= 0; --i)
        {
            int val = (num >> (4 * i)) & 0xf;
            if (ans.length() > 0 || val > 0)
            {
                char digit;
                if (val < 10)
                    digit = '0' + val;
                else
                    digit = 'a' + val - 10;
                ans += digit;
            }
        }
        return ans;
    }
};
// @lc code=end

