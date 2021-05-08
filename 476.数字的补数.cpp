/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        int t = (log10(num) / log10(2)) + 1;
        return num ^ ((long)(1 << t) - 1);
        // return (long)(1<<t)-1-num;
    }
};
// @lc code=end
