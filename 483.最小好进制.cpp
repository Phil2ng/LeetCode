/*
 * @lc app=leetcode.cn id=483 lang=cpp
 *
 * 数学性质+二分法
 * 
 * [483] 最小好进制
 */

// @lc code=start
class Solution
{
public:
    string smallestGoodBase(string n)
    {
        long long num = stoll(n);
        int m = floor(log(num) / log(2));
        for (int len = m; len > 1; len--)
        {
            long long k_low = 2, k_high = floor(pow(num, 1.0 / len));
            while (k_low < k_high)
            {
                long long mid = k_low + (k_high - k_low) / 2;
                long long res = helper(mid, len);
                if (res >= num)
                    k_high = mid;
                else if (res < num)
                    k_low = mid + 1;
            }
            long long res = helper(k_low, len);
            if (res == num)
                return to_string(k_low);
        }
        return to_string(num - 1);
    }
    long long helper(long long k, long long m)
    {
        long long ret = 1, mul = 1;
        while (m--)
        {
            mul *= k;
            ret += mul;
        }
        return ret;
    }
};
// @lc code=end
