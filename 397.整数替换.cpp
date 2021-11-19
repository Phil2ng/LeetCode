/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * 模拟,可以加记忆化
 * 
 * [397] 整数替换
 */

// @lc code=start

class Solution
{
public:
    int integerReplacement(int n)
    {
        return fun(n);
    }
    long fun(long n)
    {
        if (n == 1)
            return 0;
        if (n % 2 == 0)
        {
            return fun(n / 2) + 1;
        }
        else
        {
            return min(fun(n + 1), fun(n - 1)) + 1;
        }
    }
};
// @lc code=end

