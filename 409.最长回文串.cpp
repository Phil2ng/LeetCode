/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> count;
        int ans = 0;
        for (char c : s)
            ++count[c];
        for (auto &p : count)
        {
            ans += p.second / 2 * 2;
            if (p.second % 2 == 1 && ans % 2 == 0)
                ++ans;
        }
        return ans;
    }
};
// @lc code=end
