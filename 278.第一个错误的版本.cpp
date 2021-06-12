/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * 二分法, lower_bound()
 * 
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int first = 0, len = n;
        while (len > 0)
        {
            int half = len >> 1, mid = first + half;
            if (!isBadVersion(mid + 1))
            {
                first = mid + 1;
                len = len - half - 1;
            }
            else
                len = half;
        }
        return first + 1;
    }
};
// @lc code=end
