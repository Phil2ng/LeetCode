/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * 遍历
 * 
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> cnt(26);
        for (auto &&c : magazine)
        {
            cnt[c - 'a']++;
        }
        for (auto &&c : ransomNote)
        {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

