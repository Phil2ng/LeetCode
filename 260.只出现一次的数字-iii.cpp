/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long tmp = 0;
        for (int num : nums)
        {
            tmp ^= num;
        }
        long div = tmp & (-tmp);
        int a = 0, b = 0;
        for (int num : nums)
        {
            if (num & div)
                a ^= num;
            else
                b ^= num;
        }
        return vector<int>{a, b};
    }
};
// @lc code=end
