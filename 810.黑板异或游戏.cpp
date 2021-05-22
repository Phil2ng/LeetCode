/*
 * @lc app=leetcode.cn id=810 lang=cpp
 *
 * 贪心法,理解题意可以用数学性质
 * 
 * [810] 黑板异或游戏
 */

// @lc code=start
class Solution
{
public:
    bool xorGame(vector<int> &nums)
    {
        vector<bool> vis(nums.size(), false);
        int t = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        return t == 0 || xorGameAB(nums, 0, vis, t);
    }
    bool xorGameAB(vector<int> &nums, int step, vector<bool> &vis, int t)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                if ((t ^ nums[i]) != 0)
                {
                    vis[i] = true;
                    t ^= nums[i];
                    return xorGameAB(nums, step + 1, vis, t);
                }
            }
        }
        return (step % 2) == 1;
    }
};
// @lc code=end
