/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * 埃氏筛选法
 * [204] 计数质数
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        vector<int> prime(n, true);
        int i = 3, sqrtn = sqrt(n), count = n / 2 ;
        while (i <= sqrtn)
        {
            for (int j = i * i; j < n; j += 2 * i)
            {
                if (prime[j])
                {
                    --count;
                    prime[j] = false;
                }
            }
            do
            {
                i += 2;
            } while (i < sqrtn && !prime[i]);
        }
        return count;
    }
};
// @lc code=end
