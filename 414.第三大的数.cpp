/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * 一次遍历
 * 或set有序集合
 * 
 * [414] 第三大的数
 */

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int *a = nullptr, *b = nullptr, *c = nullptr;
        for (auto &&num : nums)
        {
            if (a == nullptr || *a < num)
            {
                c = b;
                b = a;
                a = &num;
            }
            else if (*a > num && (b == nullptr || *b < num))
            {
                c = b;
                b = &num;
            }
            else if (b != nullptr && *b > num && (c == nullptr || *c < num))
            {
                c = &num;
            }
        }
        return c == nullptr ? *a : *c;
    }
};
// @lc code=end

