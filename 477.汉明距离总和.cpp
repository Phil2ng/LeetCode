/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int ans = 0, t = 1, M = pow(10, 9), n = nums.size();
        while (t <= M)
        {
            int cnt0 = 0, cnt1 = 0;
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] & t)
                    ++cnt1;
                else
                    ++cnt0;
            }
            ans += cnt0 * cnt1;
            t = t << 1;
        }
        return ans;
    }
};
// @lc code=end
