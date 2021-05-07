/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        } while (slow != fast);
        return slow == 1;
    }
    int getNext(int n)
    {
        int ret = 0;
        while (n)
        {
            ret += (n % 10) * (n % 10);
            n /= 10;
        }
        return ret;
    }
};
// @lc code=end
